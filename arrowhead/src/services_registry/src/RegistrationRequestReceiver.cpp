#include "rclcpp/rclcpp.hpp"
#include "services_registry_interfaces/srv/registration_interface.hpp"
#include "../include/services_registry/ServiceRegister.hpp"

#include <memory>
#include <unordered_map>
#include <functional>

void registration(const std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface::Request> request,
          std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface::Response> response)
{
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request ...\n");

  ServiceRegister serviceRegister(request->registration_data_json);

  if (request->method == "register") {

    response->value_returned = serviceRegister.registerService();

  } else if (request->method == "update") {

    response->value_returned = serviceRegister.updateExpirationDay(request->service_id_with_update);

  } else if (request->method == "delete") {

    response->value_returned = serviceRegister.deleteService();

  }else {

    response->value_returned = -1;

  }

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response ...\n");
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  std::string serviceName = argv[1];

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("services_registration_server");

  rclcpp::Service<services_registry_interfaces::srv::RegistrationInterface>::SharedPtr service =
    node->create_service<services_registry_interfaces::srv::RegistrationInterface>(serviceName, &registration);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to register services.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}