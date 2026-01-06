template<typename MsgType>
VehicleService<MsgType>::VehicleService(const std::string& simulationConfigurationFilePath, const std::string& baseQueryConfigurationFilePath, const std::string& discoveryServiceName) : Node("VehicleService"), discoveryRequester(baseQueryConfigurationFilePath, discoveryServiceName)
{

  readFromConfigurationFileOfCarPath(simulationConfigurationFilePath);

  sub_car_position = this->create_subscription<std_msgs::msg::Float32>(vehicleName, 10, std::bind(&VehicleService::vehicleRelativePositionCallback, this, std::placeholders::_1));
}

template<typename MsgType>
void VehicleService<MsgType>::readFromConfigurationFileOfCarPath(const std::string& configurationFile){

  ptree configurationData;
  json_parser::read_json(configurationFile, configurationData);

  totalDistance = configurationData.get<float>("totalDistance");
  distanceToLookForOthersRSUs = configurationData.get<float>("distanceToLookForOthersRSUs");
  vehicleName = configurationData.get<std::string>("vehicleName");

  ptree rsusOnThePath = configurationData.get_child("highwayEntrances");
  
  for (auto& information : rsusOnThePath){

    float relativePosition = information.second.get<float>("relativePosition");

    information.second.erase("relativePosition");

    std::ostringstream os;
    write_json(os, information.second, true);

    int position = ((int)(relativePosition / distanceToLookForOthersRSUs));
    

    if (position > 0){

      int previousPosition = position - 1;
      mapWithRSUsOnThePath[previousPosition].push_back(os.str());

    }else {

      mapWithRSUsOnThePath[position].push_back(os.str());

    }

  }

  int totalPositions = ((int)(totalDistance / distanceToLookForOthersRSUs));
  alreadyCheckedRSUs.resize(totalPositions);

  for (int i = 0; i < totalPositions; i++){

    alreadyCheckedRSUs[i] = false;

  }

}

template<typename MsgType>
void VehicleService<MsgType>::checkForNearRSUs(){

  int positionToMap = ((int)(carRelativePosition / distanceToLookForOthersRSUs));

  if (alreadyCheckedRSUs[positionToMap] == false){

    alreadyCheckedRSUs[positionToMap] = true;
    std::cout << "\n########## [INFO] Starting the search process for RSUs ... ##########\n" << std::endl;

    int rsusToAdd = 0;

    try{

      std::vector<std::string> rsus = mapWithRSUsOnThePath.at(positionToMap);
      std::cout << "[INFO] Searching for ..." << std::endl;
      
      for (const auto& information : rsus){

        std::cout << information << std::endl;
        
      }

      std::vector<std::string> nearServicesTopicsName = discoveryRequester.requestROS2ServerForServices(rsus);

      std::cout << "[INFO] Starting the Subscription process ..." << std::endl;

      for (const auto& topicName : nearServicesTopicsName){

        auto callback = [this, topicName](const typename MsgType::SharedPtr msg) {
              this->topic_callback(msg, topicName);
        };

        subscriptions.push_back(this->create_subscription<MsgType>(
        topicName, 10, callback));

        std::cout << "[INFO] Subscribed to " << topicName << std::endl;

        rsusToAdd++;

      }

    }catch(const std::out_of_range& exception){

      std::cout << "[INFO] There are not close RSUs" << std::endl;

    }

    totalOfLastRSUs[0] = totalOfLastRSUs[1];
    totalOfLastRSUs[1] = totalOfLastRSUs[2];
    totalOfLastRSUs[2] = totalOfLastRSUs[3];
    totalOfLastRSUs[3] = rsusToAdd;

    if(positionToMap >= 3){

      std::cout << "[INFO] Starting the unsubscribe process ..." << std::endl;

      int rsusToRemove = totalOfLastRSUs[0];
      subscriptions.erase(subscriptions.begin(), subscriptions.begin() + rsusToRemove);

      if (rsusToRemove > 0){

        std::cout << "[INFO] Unsubscribing the Last " << rsusToRemove << " RSUs" << std::endl;

      }else {

        std::cout << "[INFO] There are not RSUs to unsubscribe" << std::endl;

      }

    }

  }

}

template<typename MsgType>
void VehicleService<MsgType>::vehicleRelativePositionCallback(const std_msgs::msg::Float32::SharedPtr msg){

  carRelativePosition = msg->data;

  if (carRelativePosition >= totalDistance){

    std::cout << "[INFO] The Car has arrived!" << std::endl;
    std::terminate();

  }

  std::cout << "[INFO] Car Position -> " << carRelativePosition << std::endl;

  std::thread threadForSearchingRSUs(&VehicleService::checkForNearRSUs, this);
  threadForSearchingRSUs.detach();

}