#!/usr/bin/env python3

import rclpy
import math
import time 
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid, Odometry
from std_msgs.msg import Header
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
import numpy as np
from etsi_its_msgs.msg import CAM
from geometry_msgs.msg import PolygonStamped, Point
from std_msgs.msg import Float32
class CamReceiver(Node):

    def __init__(self):
        super().__init__('cam_receiver')
        qos_profile = QoSProfile(
            depth=1,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL)
        qos_profile_2 = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE)    
        self.subscription1 = self.create_subscription(CAM, '/prius/cam_in', self.callback3, 10)
        self.occupancygrid_pub = self.create_publisher(OccupancyGrid, '/central/occupancygrid', qos_profile)
        self.timediff_pub = self.create_publisher(Float32,'/time_diff_with', 10)

        self.subscription2 = self.create_subscription(PolygonStamped, '/prius/global_costmap/published_footprint', self.callback2, qos_profile_2)
        self.subscription3 = self.create_subscription(OccupancyGrid, '/prius/global_costmap/costmap', self.callback1, qos_profile)
        self.subscription4 = self.create_subscription(Odometry, '/prius/odom', self.callback4, qos_profile_2)
        self.published = False
        self.latest_footprint = None
        self.latest_odometry = None 
        self.previous_time_sys = time.time()
        self.previous_time_sim = self.get_clock().now().to_msg()


    def callback1(self, msg):
        #Receive prius global costmap
        if not self.published:
            self.occupancygrid_pub.publish(msg)
            self.get_logger().info('Published initial costmap')
            self.published = True

    def callback2(self, msg):
        #Get the prius footprint
        if msg != None:
            self.latest_footprint = msg

    def callback4(self, msg):
        #Get latest Odometry
        self.latest_odometry = msg    

    def callback3(self, msg):
        # Get the current time when the message is received
        #self.current_time = self.get_clock().now()
        # Retrieve the costmap data
        costmap_data = msg.occupancygrid.data
        costmap_width = msg.occupancygrid.info.width
        costmap_height = msg.occupancygrid.info.height
        footprint_points = self.latest_footprint.polygon.points

        robot_pose_x = self.latest_odometry.pose.pose.position.x
        robot_pose_y = self.latest_odometry.pose.pose.position.y
        robot_pose_theta = self.latest_odometry.pose.pose.orientation.z


        # Modify the costmap data to clear (remove obstacles from) the identified cells
        costmap_origin_x = msg.occupancygrid.info.origin.position.x
        costmap_origin_y = msg.occupancygrid.info.origin.position.y
        costmap_resolution = msg.occupancygrid.info.resolution

        footprint_points = self.latest_footprint.polygon.points
        min_x = min(point.x for point in footprint_points)
        max_x = max(point.x for point in footprint_points)
        min_y = min(point.y for point in footprint_points)
        max_y = max(point.y for point in footprint_points)

        # Calculate the grid indices corresponding to the rectangle bounds
        min_grid_x = (min_x - costmap_origin_x) / costmap_resolution
        max_grid_x = (max_x - costmap_origin_x) / costmap_resolution
        min_grid_y = (min_y - costmap_origin_y) / costmap_resolution
        max_grid_y = (max_y - costmap_origin_y) / costmap_resolution

        # Iterate over the cells inside the rectangle
        for grid_x in range(int(min_grid_x), int(max_grid_x) + 1):
            for grid_y in range(int(min_grid_y), int(max_grid_y) + 1):
                # Check if the grid indices are within the valid range
                if 0 <= grid_x < costmap_width and 0 <= grid_y < costmap_height:
                    # Calculate the corresponding world coordinates
                    world_x = grid_x * costmap_resolution + costmap_origin_x
                    world_y = grid_y * costmap_resolution + costmap_origin_y

                    # Check if the world coordinates are inside the rectangle
                    if min_x <= world_x <= max_x and min_y <= world_y <= max_y:
                        index = grid_y * costmap_width + grid_x
                        costmap_data[index] = 0

        # Publish the modified costmap data as the merged costmap
        merged_costmap_msg = OccupancyGrid()
        merged_costmap_msg.header = Header()
        merged_costmap_msg.header.stamp = self.get_clock().now().to_msg()
        merged_costmap_msg.header.frame_id = 'map'
        merged_costmap_msg.info = msg.occupancygrid.info
        merged_costmap_msg.data = costmap_data

        self.occupancygrid_pub.publish(merged_costmap_msg)

        #time_difference_seconds = time_difference.nanoseconds / 1e9
        #rounded_time_difference = round(time_difference_seconds, 1)

        # The previous time is obtained when the message is sent
        #self.previous_time = self.get_clock().now()
        current_time = self.get_clock().now().to_msg()
        current_time_sys = time.time()
        time_diff_sys = current_time_sys - self.previous_time_sys
        #time_lastmessage_nanosec = current_time.nanosec - self.previous_time_sim.nanosec
        #time_lastmessage_sec = current_time.sec - self.previous_time_sim.sec

        #if time_lastmessage_nanosec < 0:
        #    time_lastmessage_sec -= 1
        #    time_lastmessage_nanosec += 1e9
        current_time_nanoseconds = current_time.sec * 1e9 + current_time.nanosec
        previous_time_nanoseconds = self.previous_time_sim.sec * 1e9 + self.previous_time_sim.nanosec
        time_lastmessage_seconds = (current_time_nanoseconds - previous_time_nanoseconds) / 1e9

        message_time = msg.occupancygrid.header.stamp
        message_time_nanoseconds = message_time.sec * 1e9 + message_time.nanosec
        time_difference_seconds = (current_time_nanoseconds - message_time_nanoseconds) / 1e9
    
        rounded_time_difference = round(time_difference_seconds, 1)
        # Publish the time difference as a Float32 message
        msg = Float32()
        msg.data = time_difference_seconds
        self.timediff_pub.publish(msg)

        self.get_logger().info('Received CAM message and OccupancyGrid message published successfully')
        self.get_logger().info('[Seconds] Current time (%s), Message time(%s)' % (current_time.sec, message_time.sec))
        self.get_logger().info('[Nanoseconds] Current time (%s), Message time(%s)' % (current_time.nanosec, message_time.nanosec))
        self.get_logger().info('Difference (%s s)' % (time_difference_seconds))
        self.get_logger().info('[Sim_Time] Time Since Last Sent Message (%s s)' % (time_lastmessage_seconds))
        self.get_logger().info('[Sys_Time] Time Since Last Sent Message (%s s)' % (time_diff_sys))
        self.previous_time_sys = time.time()
        self.previous_time_sim = self.get_clock().now().to_msg()

       
def main(args=None):
    rclpy.init(args=args)
    cam_receiver = CamReceiver()
    rclpy.spin(cam_receiver)
    cam_receiver.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
