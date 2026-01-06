#include "../include/car_package/TrafficService.hpp"

TrafficService::TrafficService(const std::string& simulationConfigurationFilePath, const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName) : VehicleService<std_msgs::msg::String>(simulationConfigurationFilePath, baseQueryConfigurationFilePath, discoveryServiceName) {
    
}

 void TrafficService::topic_callback(const std_msgs::msg::String::SharedPtr msg, const std::string& topicName){

    std::string str = msg->data.c_str();
    std::istringstream iss(str);
    std::string token;
    int numbers[2];
    int count = 0;
    while(std::getline(iss, token, '+'))
    {
        numbers[count] = std::stoi(token);
        count++;
    }
    int sum = numbers[0] + numbers[1];
    RCLCPP_INFO(this->get_logger(), "I heard: '%s' from %s", msg->data.c_str(), topicName.c_str());
    RCLCPP_INFO(this->get_logger(), "Sum = '%d'", sum);

}