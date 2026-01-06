#include "rclcpp/rclcpp.hpp"
#include "../include/cpp_pubsub/PoliceService.hpp"


int main(int argc, char * argv[])
{

  if (argc < 4)
  {
    std::cerr << "[ERROR] You need to specify the configuration file path, the period to update the service and the registry service name" << std::endl;
    return 1;
  }

  rclcpp::init(argc, argv);

  std::string configurationFilePath = argv[1];
  int periodToUpdate = std::stoi(argv[2]);
  std::string registryServiceName = argv[3];
  
  rclcpp::spin(std::make_shared<PoliceService>(configurationFilePath, periodToUpdate, registryServiceName));
  rclcpp::shutdown();

  return 0;
}