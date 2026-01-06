#include "../include/car_package/DiscoveryRequester.hpp"

DiscoveryRequester::DiscoveryRequester(const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName)
{

    ptree baseConfigurationData;
    json_parser::read_json(baseQueryConfigurationFilePath, baseConfigurationData);
    std::stringstream ss;
    write_json(ss, baseConfigurationData, true);
    baseConfiguration = ss.str();

    node = std::make_shared<rclcpp::Node>("DiscoveryRequester");
    client = node->create_client<services_discovery_interfaces::srv::RequestInterface>(discoveryServiceName);
    request = std::make_shared<services_discovery_interfaces::srv::RequestInterface::Request>();
    request->json_base_configuration = baseConfiguration;

}

std::vector<std::string> DiscoveryRequester::requestROS2ServerForServices(std::vector<std::string> rsus)
{

    request->services_to_look_for = rsus;

    short tries = 0;
    while (!client->wait_for_service(1s) && rclcpp::ok() && tries < 3) {
        if (!rclcpp::ok()) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
        tries++;
    }

    if (tries >= 3){

        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "The Discovery service is not available");
        return std::vector<std::string>();

    }

    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {

        for (auto service : result.get()->services_found)
        {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service found: %s", service.c_str());
        }

    } else {

        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");

    }

    return result.get()->services_found;

}