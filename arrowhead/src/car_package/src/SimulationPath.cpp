#include "../include/car_package/SimulationPath.hpp"

SimulationPath::SimulationPath(const std::string& simulationConf) : Node("SimulationPath"){

    vehicleRelativePosition = 0;
    readFromConfigurationFileOfCarPath(simulationConf);
    publish_position = this->create_publisher<std_msgs::msg::Float32>(vehicleName, 10);
    timerToUpdateCarPosition = this->create_wall_timer(1s, std::bind(&SimulationPath::updateVehicleRelativePosition, this));

}

void SimulationPath::readFromConfigurationFileOfCarPath(const std::string& configurationFile){

  ptree configurationData;
  json_parser::read_json(configurationFile, configurationData);

  totalDistance = configurationData.get<float>("totalDistance");
  vehicleVelocity = configurationData.get<float>("vehicleVelocity");
  vehicleName = configurationData.get<std::string>("vehicleName");

}

void SimulationPath::updateVehicleRelativePosition(){

    vehicleRelativePosition += vehicleVelocity;
    auto message = std_msgs::msg::Float32();
    message.data = vehicleRelativePosition;
    publish_position->publish(message);

    if (vehicleRelativePosition >= totalDistance){

        std::cout << "[INFO] The Car has arrived!" << std::endl;
        std::terminate();

    }

    std::cout << "[INFO] Car Position -> " << vehicleRelativePosition << std::endl;

}