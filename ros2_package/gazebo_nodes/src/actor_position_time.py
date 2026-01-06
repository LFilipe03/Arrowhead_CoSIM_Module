#!/usr/bin/env python3

import rclpy
import math
import time 
from rclpy.node import Node
from nav_msgs.msg import OccupancyGrid, Odometry
from std_msgs.msg import Header
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
import numpy as np
from gazebo_msgs.msg import ModelStates

from std_msgs.msg import Float32
class ActorPositonTime(Node):

    def __init__(self):
        super().__init__('actor_position_time')
        self.subscription1 = self.create_subscription(ModelStates, '/model_states', self.callback1, 10)
        #self.previous_time = time.time()

    def callback1(self, msg):
        current_time = self.get_clock().now().to_msg()
        # Retrieve data from the desired model name
        model_names = msg.name
        model_poses = msg.pose
        for i, name in enumerate(model_names):
            if name == "actor1":
                pose = model_poses[i]
                # Process or use the pose data for the desired model
                # Example: Print the position of actor1
                self.get_logger().info("Actor1 Position: {}".format(pose.position))
        
        self.get_logger().info('Current time (%ss), (%sns)' % (current_time.sec, current_time.nanosec))
        #self.get_logger().info('[Seconds] Current time (%s), Message time(%s)' % (current_time.sec, message_time.sec))
        #self.get_logger().info('[Nanoseconds] Current time (%s), Message time(%s)' % (current_time.nanosec, message_time.nanosec))
        #self.get_logger().info('Difference (%s s) (%s ns)' % (time_difference_seconds, time_difference_nanosec))

       
def main(args=None):
    rclpy.init(args=args)
    actor_position_time = ActorPositonTime()
    rclpy.spin(actor_position_time)
    actor_position_time.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
