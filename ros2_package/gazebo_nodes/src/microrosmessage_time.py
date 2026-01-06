#!/usr/bin/env python3

import rclpy
import math
import time 
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid, Odometry
from std_msgs.msg import Header
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
import numpy as np
from std_msgs.msg import Float32
from sensor_msgs.msg import LaserScan
class MicroRosMsgTime(Node):

    def __init__(self):
        super().__init__('microros_message_time')

        qos_profile = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE)

        qos_profile_2 = QoSProfile(
            depth=5,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE)      


        self.subscription1 = self.create_subscription(LaserScan, '/microros/sensor1/outside_scan', self.callback1, qos_profile)
        #self.subscription1 = self.create_subscription(LaserScan, '/microros/sensor1/outside_scan', self.callback1, qos_profile_2)
        self.timediff_pub = self.create_publisher(Float32,'/microros_msg_time', 10)
        self.previous_time = time.time()

    def callback1(self, msg):
        current_time = self.get_clock().now().to_msg()
        current_time_sys = time.time()
        time_diff_sys = current_time_sys - self.previous_time
        #time_lastmessage_nanosec = current_time.nanosec - self.previous_time.nanosec
        #time_lastmessage_sec = time_lastmessage_nanosec / 1e9

        message_time = msg.header.stamp
        time_difference_nanosec = current_time.nanosec - message_time.nanosec
        time_difference_sec = current_time.sec - message_time.sec


        #time_difference_seconds = time_difference_nanosec / 1e9
        if time_difference_nanosec < 0:
            time_difference_sec -= 1
            time_difference_nanosec += 1e9

        time_difference_seconds = time_difference_sec + time_difference_nanosec / 1e9

        rounded_time_difference = round(time_difference_seconds, 1)
        # Publish the time difference as a Float32 message
        new_msg = Float32()
        new_msg.data = time_difference_seconds
        self.timediff_pub.publish(new_msg)

        self.get_logger().info('[Seconds] Current time (%s), Message time(%s)' % (current_time.sec, message_time.sec))
        self.get_logger().info('[Nanoseconds] Current time (%s), Message time(%s)' % (current_time.nanosec, message_time.nanosec))
        self.get_logger().info('Difference (%s s) (%s ns)' % (time_difference_seconds, time_difference_nanosec))
        #self.get_logger().info('Time Since Last Sent Message (%s s) (%s ns)' % (time_lastmessage_sec, time_lastmessage_nanosec))
        self.get_logger().info('Time Since Last Sent Message (%s s)' % (time_diff_sys))
        self.previous_time = time.time()

       
def main(args=None):
    rclpy.init(args=args)
    microros_msg_time = MicroRosMsgTime()
    rclpy.spin(microros_msg_time)
    microros_msg_time.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
