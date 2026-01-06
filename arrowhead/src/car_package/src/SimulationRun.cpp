#include "../include/car_package/SimulationPath.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{

    if (argc < 2)
    {
        std::cerr << "[ERROR] You need to specify the configuration file of The Simulation" << std::endl;
        return 1;
    }

    std::string simulationConfigurationFile = argv[1];

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimulationPath>(simulationConfigurationFile));
    rclcpp::shutdown();

    return 0;
}