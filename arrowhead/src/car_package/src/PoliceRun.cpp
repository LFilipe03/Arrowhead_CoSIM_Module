#include "../include/car_package/PoliceService.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{

    if (argc < 4)
    {
        std::cerr << "[ERROR] You need to specify the configuration file of The Path, the base query configuration and the discovery service name" << std::endl;
        return 1;
    }

    std::string simulationConfigurationFile = argv[1];
    std::string baseQueryConfigurationFile = argv[2];
    std::string discoveryServiceName = argv[3];

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoliceService>(simulationConfigurationFile, baseQueryConfigurationFile, discoveryServiceName));
    rclcpp::shutdown();

    return 0;
}