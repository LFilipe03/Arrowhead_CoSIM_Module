
#include "rclcpp/rclcpp.hpp"

#include "micro_its_msgs/msg/cam.hpp"
#include "micro_msgs/srv/identifier.hpp"

class OmnetCamFilter : public rclcpp::Node
{
    public:
        OmnetCamFilter(int identifier);
    private:
        void cam_callback(const micro_its_msgs::msg::CAM::SharedPtr msg);
        void filter_service_callback(const std::shared_ptr<micro_msgs::srv::Identifier::Request> request, std::shared_ptr<micro_msgs::srv::Identifier::Response> response);
        rclcpp::Publisher<micro_its_msgs::msg::CAM>::SharedPtr cam_publisher_;
        rclcpp::Subscription<micro_its_msgs::msg::CAM>::SharedPtr cam_subscriber_;
        rclcpp::Service<micro_msgs::srv::Identifier>::SharedPtr service_;

        int identifier_ = 0;
};
