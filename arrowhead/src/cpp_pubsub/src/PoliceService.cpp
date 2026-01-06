#include "../include/cpp_pubsub/PoliceService.hpp"

PoliceService::PoliceService(std::string configurationFilePath, int periodToUpdate, std::string registryServiceName) : RSUService <std_msgs::msg::Int32>(configurationFilePath, periodToUpdate, registryServiceName) {

    timer = this->create_wall_timer(2s, std::bind(&PoliceService::rsu_service, this));

}

void PoliceService::rsu_service(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(50, 200);

    auto message = std_msgs::msg::Int32();
    message.data = dis(gen);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
    publisher->publish(message);

}