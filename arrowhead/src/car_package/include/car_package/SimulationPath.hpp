#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

using namespace std::chrono_literals;
using namespace boost::property_tree;

class SimulationPath : public rclcpp::Node{

    public:

        SimulationPath(const std::string& simulationConf);

    private:

        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publish_position;
        rclcpp::TimerBase::SharedPtr timerToUpdateCarPosition;

        std::string vehicleName;

        float vehicleVelocity;
        float totalDistance;
        float vehicleRelativePosition;

        void readFromConfigurationFileOfCarPath(const std::string& configurationFile);
        void createSharedMemory();
        void updateVehicleRelativePosition();

};