#include "rclcpp/rclcpp.hpp"
#include "arrowhead_msgs/msg/service_registration.hpp"
#include "arrowhead_msgs/msg/service_data.hpp"
#include "arrowhead_msgs/msg/provider_system.hpp"
#include "arrowhead_msgs/msg/service_metadata.hpp"

using namespace std::chrono_literals;

class RegistrationPublisher : public rclcpp::Node
{
public:
  RegistrationPublisher()
  : Node("registration_publisher")
  {
    publisher_ = this->create_publisher<arrowhead_msgs::msg::ServiceRegistration>(
      "Arrowhead_Service_Registry", 10);

    timer_ = this->create_wall_timer(
      2s, std::bind(&RegistrationPublisher::publish_message, this));
  }

private:
  void publish_message()
  {
    arrowhead_msgs::msg::ServiceRegistration msg;

    msg.service_validation = 96;
    msg.server_addrport = "192.168.1.225:8443";

    // ----- Metadata -----
    arrowhead_msgs::msg::ServiceMetadata metadata;
    metadata.highway_name = "A3";
    metadata.entrance_number = 1;

    // ----- Provider System -----
    arrowhead_msgs::msg::ProviderSystem provider;
    provider.address = "1.1.1.1";
    provider.authentication_info = "None";
    provider.metadata = metadata;
    provider.port = 1;
    provider.system_name = "RSU-1";

    // ----- Service Data -----
    arrowhead_msgs::msg::ServiceData service_data;
    service_data.interfaces = {"HTTP-INSECURE-JSON"};
    service_data.metadata = metadata;
    service_data.provider_system = provider;
    service_data.secure = "NOT_SECURE";
    service_data.service_definition = "Traffic-Information";
    service_data.service_uri = "Traffic_Information_1";
    service_data.version = 1;

    msg.service_data = service_data;

    publisher_->publish(msg);

    RCLCPP_INFO(this->get_logger(), "Published ServiceRegistration message");
  }

  rclcpp::Publisher<arrowhead_msgs::msg::ServiceRegistration>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RegistrationPublisher>());
  rclcpp::shutdown();
  return 0;
}
