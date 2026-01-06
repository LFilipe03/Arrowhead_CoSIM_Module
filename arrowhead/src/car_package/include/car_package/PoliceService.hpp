#include "VehicleService.hpp"
#include "std_msgs/msg/int32.hpp"

class PoliceService : public VehicleService<std_msgs::msg::Int32>{

    public:

        PoliceService(const std::string& simulationConfigurationFilePath, const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName);

    private:
    
        void topic_callback(const typename std_msgs::msg::Int32::SharedPtr msg, const std::string& topicName) override;

};