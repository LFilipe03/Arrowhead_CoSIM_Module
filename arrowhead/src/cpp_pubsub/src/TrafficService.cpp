#include "../include/cpp_pubsub/TrafficService.hpp"

TrafficService::TrafficService(std::string configurationFilePath, int periodToUpdate, std::string registryServiceName) : RSUService <std_msgs::msg::String>(configurationFilePath, periodToUpdate, registryServiceName) {

    timer = this->create_wall_timer(2s, std::bind(&TrafficService::rsu_service, this));

}

void TrafficService::rsu_service(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(50, 200);

    auto message = std_msgs::msg::String();
    message.data = std::to_string(dis(gen)) + "+" + std::to_string(dis(gen));
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher->publish(message);

}