#include "../include/car_package/PoliceService.hpp"

PoliceService::PoliceService(const std::string& simulationConfigurationFilePath, const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName) : VehicleService<std_msgs::msg::Int32>(simulationConfigurationFilePath, baseQueryConfigurationFilePath, discoveryServiceName) {
    
}

void PoliceService::topic_callback(const typename std_msgs::msg::Int32::SharedPtr msg, const std::string& topicName){

    int speedLimit = 120;
    int number = msg->data;

    RCLCPP_INFO(this->get_logger(), "I heard: '%d' from %s", number, topicName.c_str());

    if (number > speedLimit){

        RCLCPP_INFO(this->get_logger(), "Speeding at : '%d'", number);

    }else {

        RCLCPP_INFO(this->get_logger(), "Not Speeding at : '%d'", number);

    }
}