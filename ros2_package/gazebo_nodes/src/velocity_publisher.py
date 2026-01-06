#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class PriusCmdVelPublisher(Node):
    def __init__(self):
        super().__init__('prius_cmd_vel_publisher')
        self.publisher_ = self.create_publisher(Twist, '/prius_lite/cmd_vel', 10)
        timer_period = 0.1  # Publish at 10 Hz
        self.timer = self.create_timer(timer_period, self.publish_cmd_vel)
        #self.get_logger().info('Publisher for /prius_lite/cmd_vel started.')

    def publish_cmd_vel(self):
        msg = Twist()
        msg.linear.x = 10.0
        msg.linear.y = 0.0
        msg.linear.z = 0.0
        msg.angular.x = 0.0
        msg.angular.y = 0.0
        msg.angular.z = 0.0
        self.publisher_.publish(msg)
        #self.get_logger().info(f'Publishing: {msg}')

def main(args=None):
    rclpy.init(args=args)
    node = PriusCmdVelPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
