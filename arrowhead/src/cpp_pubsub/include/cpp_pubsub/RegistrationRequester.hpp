#include <chrono>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "services_registry_interfaces/srv/registration_interface.hpp"

using namespace std::chrono_literals;
using namespace boost::property_tree;

class RegistrationRequester{

    public:

        RegistrationRequester(const std::string& configurationFile, const std::string& registryServiceName);

        std::string getTopicName();

        int requestROS2ServerForRegistration();
        int requestROS2ServerForUpdate(int serviceId);
        int requestROS2ServerForElimination();

    private:

        std::string configurationData;
        std::string topicName;
        std::shared_ptr<rclcpp::Node> node;

        rclcpp::Client<services_registry_interfaces::srv::RegistrationInterface>::SharedPtr client;
        std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface::Request> request;

        int makeRequest();

};

