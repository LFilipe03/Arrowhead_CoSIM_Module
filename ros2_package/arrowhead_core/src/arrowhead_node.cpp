#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "arrowhead_msgs/msg/service_registration.hpp"
#include "arrowhead_msgs/msg/service_data.hpp"
#include "arrowhead_msgs/msg/provider_system.hpp"
#include "arrowhead_msgs/msg/service_metadata.hpp"
#include "arrowhead_msgs/msg/arrowhead_response.hpp"

using namespace std::chrono_literals;

class ArrowheadNode : public rclcpp::Node
{
public:
  ArrowheadNode()
  : Node("arrowhead_node")
  {
    registration_publisher_ = this->create_publisher<arrowhead_msgs::msg::ServiceRegistration>(
      "Arrowhead_Service_Registry", 10);

    request_publisher_ = this->create_publisher<std_msgs::msg::String>(
      "arrowhead_request", 10);

    response_subscriber_ = this->create_subscription<arrowhead_msgs::msg::ArrowheadResponse>(
      "arrowhead_response", 10,
      std::bind(&ArrowheadNode::on_response, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(
      2s, std::bind(&ArrowheadNode::publish_messages, this));
  }

private:
  void publish_messages()
  {
    publish_registration();
    publish_request();
  }

  void publish_registration()
  {
    arrowhead_msgs::msg::ServiceRegistration msg;

    msg.service_validation = 96;
    msg.server_addrport = "192.168.1.225:8443";

    arrowhead_msgs::msg::ServiceMetadata metadata;
    metadata.highway_name = "A3";
    metadata.entrance_number = 1;

    arrowhead_msgs::msg::ProviderSystem provider;
    provider.address = "1.1.1.1";
    provider.authentication_info = "None";
    provider.metadata = metadata;
    provider.port = 1;
    provider.system_name = "RSU-1";

    arrowhead_msgs::msg::ServiceData service_data;
    service_data.interfaces = {"HTTP-INSECURE-JSON"};
    service_data.metadata = metadata;
    service_data.provider_system = provider;
    service_data.secure = "NOT_SECURE";
    service_data.service_definition = "Traffic-Information";
    service_data.service_uri = "Traffic_Information_1";
    service_data.version = 1;

    msg.service_data = service_data;

    registration_publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Published ServiceRegistration message");
  }

  void publish_request()
  {
    std_msgs::msg::String msg;
    msg.data = "vehicle-1";

    request_publisher_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Published arrowhead_request for: %s", msg.data.c_str());
  }

  void on_response(const arrowhead_msgs::msg::ArrowheadResponse::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(),
      "Arrowhead response — system: %s, service: %s, result: %s",
      msg->system_name.c_str(),
      msg->service_definition.c_str(),
      msg->result.c_str());
  }

  rclcpp::Publisher<arrowhead_msgs::msg::ServiceRegistration>::SharedPtr registration_publisher_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr request_publisher_;
  rclcpp::Subscription<arrowhead_msgs::msg::ArrowheadResponse>::SharedPtr response_subscriber_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ArrowheadNode>());
  rclcpp::shutdown();
  return 0;
}
