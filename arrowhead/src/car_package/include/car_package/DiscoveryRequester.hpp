#include <chrono>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "services_discovery_interfaces/srv/request_interface.hpp"

using namespace std::chrono_literals;
using namespace boost::property_tree;

class DiscoveryRequester{

    public:

        DiscoveryRequester(const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName);

        std::vector<std::string> requestROS2ServerForServices(std::vector<std::string> rsus);

    private:

        std::string baseConfiguration;
        std::shared_ptr<rclcpp::Node> node;

        rclcpp::Client<services_discovery_interfaces::srv::RequestInterface>::SharedPtr client;
        std::shared_ptr<services_discovery_interfaces::srv::RequestInterface::Request> request;

};