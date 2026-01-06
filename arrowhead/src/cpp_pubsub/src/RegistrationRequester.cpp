#include "../include/cpp_pubsub/RegistrationRequester.hpp"

RegistrationRequester::RegistrationRequester(const std::string& configurationFile, const std::string& registryServiceName)
{

    ptree baseConfigurationData;
    json_parser::read_json(configurationFile, baseConfigurationData);
    topicName = baseConfigurationData.get<std::string>("serviceData.serviceUri");
    std::stringstream ss;
    write_json(ss, baseConfigurationData, true);
    configurationData = ss.str();

    node = std::make_shared<rclcpp::Node>("RegistrationRequester");
    client = node->create_client<services_registry_interfaces::srv::RegistrationInterface>(registryServiceName);
    request = std::make_shared<services_registry_interfaces::srv::RegistrationInterface::Request>();
    request->registration_data_json = configurationData;
    request->service_id_with_update = 0;

}

std::string RegistrationRequester::getTopicName()
{
    return topicName;
}

int RegistrationRequester::requestROS2ServerForRegistration()
{
    std::string method = "register";
    request->method = method;

    return makeRequest();

}

int RegistrationRequester::requestROS2ServerForUpdate(int serviceId)
{
    std::string method = "update";
    request->method = method;
    request->service_id_with_update = serviceId;

    return makeRequest();

}

int RegistrationRequester::requestROS2ServerForElimination()
{
    std::string method = "delete";
    request->method = method;

    return makeRequest();

}

int RegistrationRequester::makeRequest()
{

    short tries = 0;

    while (!client->wait_for_service(1s) && rclcpp::ok() && tries < 3) {

        if (!rclcpp::ok()) {

            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return -1;
        }

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
        tries++;

    }

    if (tries >= 3){

        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "The Registration service is not available");
        return -1;

    }

    auto result = client->async_send_request(request);
    // Wait for the result.
    if (rclcpp::spin_until_future_complete(node, result, std::chrono::seconds(30)) == rclcpp::FutureReturnCode::SUCCESS)
    {

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Return Value from Server: %d", result.get()->value_returned);

    } else {

        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
        return -1;

    }

    return result.get()->value_returned;

}
