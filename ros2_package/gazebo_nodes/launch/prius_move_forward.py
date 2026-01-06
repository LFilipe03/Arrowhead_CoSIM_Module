import rclpy
from rclpy.node import Node
from prius_msgs.msg import Control

class PriusController(Node):
    def __init__(self):
        super().__init__('prius_controller')
        qos = rclpy.qos.qos_profile_sensor_data
        self.pub = self.create_publisher(Control, 'control', qos)

    def move_forward(self, throttle=1.0, steer=0.0, brake=0.0):
        command = Control()
        command.throttle = throttle
        command.steer = steer
        command.brake = brake
        command.shift_gears = Control.FORWARD
        self.pub.publish(command)

def main(args=None):
    rclpy.init(args=args)
    controller = PriusController()
    
    # Move forward with default parameters
    controller.move_forward()

    rclpy.spin(controller)
    controller.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
