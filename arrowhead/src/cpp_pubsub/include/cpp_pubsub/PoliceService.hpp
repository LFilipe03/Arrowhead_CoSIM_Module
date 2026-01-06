#include "RSUService.hpp"
#include "std_msgs/msg/int32.hpp"
#include <random>

class PoliceService : public RSUService <std_msgs::msg::Int32>{

    public:

        PoliceService(std::string configurationFilePath, int periodToUpdate, std::string registryServiceName);

    private:

        rclcpp::TimerBase::SharedPtr timer;

        void rsu_service() override;

};