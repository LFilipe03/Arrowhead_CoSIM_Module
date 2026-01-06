#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>

int id_value = 0;
void callback(const std_msgs::msg::Int32::SharedPtr& id)
{
  std::cout << "ID: " << id->data << std::endl; 
  id_value = id->data;
}

void publishMessage(const rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr& publisher)
{
  std_msgs::msg::Int32 message;
  message.data = id_value;
  publisher->publish(message);
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  
  auto node = std::make_shared<rclcpp::Node>("microros_id");
  // Create a subscriber to the Gazebo model states topic
  

  // Create a publisher with the desired QoS profile for the published message
  auto publisher = node->create_publisher<std_msgs::msg::Int32>("/microros/id", 10);

  // Create a subscriber with the desired QoS profile for the subscribed message
  auto subscriber = node->create_subscription<std_msgs::msg::Int32> ("/microros/id",
    10,
    [&](const std_msgs::msg::Int32::SharedPtr id) {
      callback(id);
  });

 // Create a timer callback function for publishing
  auto timer_callback = [&]() {
    publishMessage(publisher);
  };

 // Create a timer with the desired duration and the callback function for publishing
  rclcpp::TimerBase::SharedPtr timer = node->create_wall_timer(
    std::chrono::seconds(5),
    timer_callback
  );  
  

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}