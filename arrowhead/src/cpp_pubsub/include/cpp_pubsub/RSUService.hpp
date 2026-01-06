#include <chrono>
#include <memory>

#include "RegistrationRequester.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

template<typename MsgType>
class RSUService : public rclcpp::Node
{
public:

  RSUService(std::string configurationFilePath, int periodToUpdate, std::string registryServiceName);

protected:

  typename rclcpp::Publisher<MsgType>::SharedPtr publisher;

private:

  int serviceId;

  RegistrationRequester registrationRequester;
  rclcpp::TimerBase::SharedPtr timerToKeepServiceAlive;

  virtual void rsu_service() = 0;
  void keepAliveTimer_callback();
  void signal_handler(int signal);

  static void static_signal_handler(int signal);

};

#include "RSUService.tpp"