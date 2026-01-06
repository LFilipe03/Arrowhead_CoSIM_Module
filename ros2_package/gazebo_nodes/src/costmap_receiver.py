#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
#from nav2_msgs.msg import OccupancyGrid
from nav_msgs.msg import OccupancyGrid
from std_msgs.msg import Header
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
import numpy as np
class CostmapReceiver(Node):

    def __init__(self):
        super().__init__('costmap_receiver')
        qos_profile = QoSProfile(
            depth=1,
            history=HistoryPolicy.KEEP_LAST,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.TRANSIENT_LOCAL)


        self.subscription1 = self.create_subscription(OccupancyGrid, '/prius/global_costmap/costmap', self.callback1, qos_profile)
        self.merged_costmap_pub = self.create_publisher(OccupancyGrid, '/prius/global_costmap/costmap', qos_profile)

        self.merged_costmap_pub2 = self.create_publisher(OccupancyGrid, '/central/occupancygrid', qos_profile)
        #Receive the OccupancyGrid
        self.subscription2= self.create_subscription(OccupancyGrid, '/central/occupancygrid', self.callback2, 10)
        self.published = False
        self.initialdata = None

    def callback1(self, msg):
        #Receive prius global costmap
        if not self.published:
            self.initialdata = msg    
            self.merged_costmap_pub2.publish(msg)
            self.get_logger().info('Published initial costmap')
            self.published = True    

    def callback2(self, msg):
        #Receive central/occupancygrid costmap
        if self.published:
            self.costmap2 = msg
            new_msg = OccupancyGrid()
            new_msg.header.stamp = self.get_clock().now().to_msg()
            new_msg.header.frame_id = self.initialdata.header.frame_id
            new_msg.info = msg.info
            new_msg.data = msg.data
            self.merged_costmap_pub2.publish(new_msg)
            self.get_logger().info('Published central costmap data')
    


       
def main(args=None):
    rclpy.init(args=args)
    costmap_receiver = CostmapReceiver()
    rclpy.spin(costmap_receiver)
    costmap_receiver.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
