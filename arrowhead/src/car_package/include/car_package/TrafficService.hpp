#include "VehicleService.hpp"
#include "std_msgs/msg/string.hpp"

class TrafficService : public VehicleService<std_msgs::msg::String>{

    public:

        TrafficService(const std::string& simulationConfigurationFilePath, const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName);

    private:
    
        void topic_callback(const std_msgs::msg::String::SharedPtr msg, const std::string& topicName) override;

};