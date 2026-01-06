#include <chrono>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <unordered_map>
#include <thread>
#include <cstdlib>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"
#include "services_discovery_interfaces/srv/request_interface.hpp"
#include "DiscoveryRequester.hpp"

template<typename MsgType>
class VehicleService : public rclcpp::Node
{
public:

  VehicleService(const std::string& simulationConfigurationFilePath, const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName);

private:

  int totalOfLastRSUs[4] = {0, 0, 0, 0};

  float carRelativePosition;
  float carVelocity;
  float totalDistance;
  float distanceToLookForOthersRSUs;

  std::string vehicleName;

  std::unordered_map<int, std::vector<std::string>> mapWithRSUsOnThePath;
  std::vector<bool> alreadyCheckedRSUs;

  std::vector<typename rclcpp::Subscription<MsgType>::SharedPtr> subscriptions;
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr sub_car_position;
  
  DiscoveryRequester discoveryRequester;

  void readFromConfigurationFileOfCarPath(const std::string& configurationFile);
  void checkForNearRSUs();
  void vehicleRelativePositionCallback(const std_msgs::msg::Float32::SharedPtr msg);

  virtual void topic_callback(const typename MsgType::SharedPtr msg, const std::string& topicName) = 0;

};

#include "VehicleService.tpp"