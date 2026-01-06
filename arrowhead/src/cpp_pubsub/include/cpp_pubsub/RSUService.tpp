template<typename MsgType>
RSUService<MsgType>* globalInstancePtr = nullptr;

template<typename MsgType>
RSUService<MsgType>::RSUService(std::string configurationFilePath, int periodToUpdate, std::string registryServiceName) : Node("information_publisher"), registrationRequester(configurationFilePath, registryServiceName)
{
  globalInstancePtr<MsgType> = this;

  std::string topicName = registrationRequester.getTopicName();
  publisher = this->create_publisher<MsgType>(topicName, 10);

  std::chrono::seconds timerToUpdate(periodToUpdate);
  timerToKeepServiceAlive = this->create_wall_timer(timerToUpdate, std::bind(&RSUService::keepAliveTimer_callback, this));
  serviceId = registrationRequester.requestROS2ServerForRegistration();

  if (serviceId == -1) {

    RCLCPP_ERROR(this->get_logger(), "Failed to register service");
    std::terminate();

  }

  RCLCPP_INFO(this->get_logger(), "Service registered successfully");

  std::signal(SIGINT, static_signal_handler);
}

template<typename MsgType>
void RSUService<MsgType>::static_signal_handler(int signal) {

  if (globalInstancePtr<MsgType> != nullptr) {

    globalInstancePtr<MsgType>->signal_handler(signal);

  }

}

template<typename MsgType>
void RSUService<MsgType>::signal_handler(int signal) {

  int result = registrationRequester.requestROS2ServerForElimination();

  if (result == -1) {
    RCLCPP_ERROR(this->get_logger(), "Failed to delete service. Contact the administrator to solve the problem.");
  } else {
    RCLCPP_INFO(this->get_logger(), "Service deleted successfully");
  }

  std::signal(SIGINT, SIG_DFL);
  std::terminate();
}

template<typename MsgType>
void RSUService<MsgType>::keepAliveTimer_callback()
{
  int result = registrationRequester.requestROS2ServerForUpdate(serviceId);

  if (result == -1) {

    RCLCPP_ERROR(this->get_logger(), "Failed to update service. Contact the administrator to solve the problem.");

  }

  RCLCPP_INFO(this->get_logger(), "Service updated successfully");

}