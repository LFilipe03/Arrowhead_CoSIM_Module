#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/range.hpp>

std::string prefix;
void callback(const sensor_msgs::msg::Range::SharedPtr& range_scan, const rclcpp::Publisher<sensor_msgs::msg::Range>::SharedPtr& publisher)
{
  // Publish the received message
  publisher->publish(*range_scan);
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  if(argc > 1){
    prefix = argv[1];
  } else {
    prefix = "";
  }
  auto node = std::make_shared<rclcpp::Node>("sensor_reliable");

  // Create a publisher with the desired QoS profile for the published message
  auto publisher = node->create_publisher<sensor_msgs::msg::Range>(prefix + "/scan_reliable", 10);

  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;

  auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 10), qos_profile);

  // Create a subscriber with the desired QoS profile for the subscribed message
  auto subscriber = node->create_subscription<sensor_msgs::msg::Range>(
    prefix + "/outside_scan",
    qos,
    [&](const sensor_msgs::msg::Range::SharedPtr range_scan) {
      callback(range_scan, publisher);
    });

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}