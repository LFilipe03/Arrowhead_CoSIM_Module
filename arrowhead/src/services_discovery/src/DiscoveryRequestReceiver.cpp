#include "rclcpp/rclcpp.hpp"
#include "services_discovery_interfaces/srv/request_interface.hpp"
#include "../include/services_discovery/ServiceDiscover.hpp"

#include <memory>

void add(const std::shared_ptr<services_discovery_interfaces::srv::RequestInterface::Request> request,
          std::shared_ptr<services_discovery_interfaces::srv::RequestInterface::Response>      response)
{

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request ...\n");

  for (auto service : request->services_to_look_for)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Looking for service: %s", service.c_str());
  }

  ServiceDiscover serviceDiscover(request->json_base_configuration);
  std::vector<std::string> servicesFound = serviceDiscover.getTopicNamesOfCloseServices(request->services_to_look_for); 
  response->services_found = servicesFound;
  
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response ...\n");

}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  std::string serviceName = argv[1];

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("services_discovery_server");

  rclcpp::Service<services_discovery_interfaces::srv::RequestInterface>::SharedPtr service =
    node->create_service<services_discovery_interfaces::srv::RequestInterface>(serviceName, &add);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to look for services from RSUs.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}