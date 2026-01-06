#include "RSUService.hpp"
#include <random>

class TrafficService : public RSUService <std_msgs::msg::String>{

    public:

        TrafficService(std::string configurationFilePath, int periodToUpdate, std::string registryServiceName);

    private:

        rclcpp::TimerBase::SharedPtr timer;

        void rsu_service() override;

};