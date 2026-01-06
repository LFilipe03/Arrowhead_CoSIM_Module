#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>


size_t estimateMessageSize(const sensor_msgs::msg::LaserScan& laser_scan)
{
  size_t fixedSize = sizeof(laser_scan.header) +
                     sizeof(laser_scan.angle_min) +
                     sizeof(laser_scan.angle_max) +
                     sizeof(laser_scan.angle_increment) +
                     sizeof(laser_scan.time_increment) +
                     sizeof(laser_scan.scan_time) +
                     sizeof(laser_scan.range_min) +
                     sizeof(laser_scan.range_max);

  size_t variableSize = laser_scan.ranges.size() * sizeof(float) +
                        laser_scan.intensities.size() * sizeof(float);

  return fixedSize + variableSize;
}

void callback(const sensor_msgs::msg::LaserScan::SharedPtr& laser_scan, const rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr& publisher)
{
 
  size_t messageSize = estimateMessageSize(*laser_scan);
  std::cout << "Received LaserScan message size: " << messageSize << " bytes" << std::endl;

  // Publish the received message
  publisher->publish(*laser_scan);
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("testing_node");
  // Create a subscriber to the Gazebo model states topic
  
  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;

  auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 10), qos_profile);

  // Create a publisher with the desired QoS profile for the published message
  auto publisher = node->create_publisher<sensor_msgs::msg::LaserScan>("/sensor1/scan_test", rclcpp::QoS(10));

  // Create a subscriber with the desired QoS profile for the subscribed message
  auto subscriber = node->create_subscription<sensor_msgs::msg::LaserScan>(
    "/sensor1/outside_scan",
    qos,
    [&](const sensor_msgs::msg::LaserScan::SharedPtr laser_scan) {
      callback(laser_scan, publisher);
    });

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
