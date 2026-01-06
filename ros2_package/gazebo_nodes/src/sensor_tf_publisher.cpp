#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <gazebo_msgs/msg/model_states.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Scalar.h>


// Declare the broadcaster at a higher scope
//tf2_ros::StaticTransformBroadcaster br;
std::string prefix;

void publishTransform(const std::shared_ptr<rclcpp::Node>& node, const gazebo_msgs::msg::ModelStates::SharedPtr& model_states, std::string name)
{
  int sensorIndex = -1;
  for (size_t i = 0; i < model_states->name.size(); i++) {
    if (model_states->name[i] == name) {
        sensorIndex = i;
    } 

  }

  static tf2_ros::StaticTransformBroadcaster br(node);
  rclcpp::Time current_time = node->now();
  // Translation transform
  geometry_msgs::msg::TransformStamped translationTransform;
  // Rotation transform
  geometry_msgs::msg::TransformStamped rotationTransform;

  // FOR SENSOR
  if(sensorIndex != -1) {
    translationTransform.header.frame_id = name + "/location";  // The frame of the Robot Sensor
    translationTransform.child_frame_id = "map";    // The frame of the Robot Central

    rotationTransform.header.frame_id = name + "/laser_link";  
    rotationTransform.child_frame_id = name + "/location";    

    // Get the position of the robot sensor from Gazebo
    const auto& pose = model_states->pose[sensorIndex];
    const auto& position = pose.position;
    const auto& orientation = pose.orientation;

    // Set the translation values based on the robot sensor position
    translationTransform.transform.translation.x = -position.x;
    translationTransform.transform.translation.y = -position.y;
    translationTransform.transform.translation.z = 0.0;

    // Set the timestamp
    translationTransform.header.stamp = current_time;

    // Set the rotation values (adjust as needed)
    rotationTransform.transform.rotation.x = -orientation.x;
    rotationTransform.transform.rotation.y = -orientation.y;
    rotationTransform.transform.rotation.z = -orientation.z;
    rotationTransform.transform.rotation.w = orientation.w;

    // Set the timestamp
    rotationTransform.header.stamp = current_time;
    br.sendTransform(translationTransform);
    br.sendTransform(rotationTransform);

  }
}

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  if(argc > 1){
    prefix = argv[1];
  } else {
    prefix = "";
  }
  auto node = std::make_shared<rclcpp::Node>("transform_publisher");

  // Create a subscriber to the Gazebo model states topic
  auto modelStatesSub = node->create_subscription<gazebo_msgs::msg::ModelStates>(
      "/model_states", 10,
      [&node](const gazebo_msgs::msg::ModelStates::SharedPtr model_states) {
        publishTransform(node, model_states, prefix);
      });

  // Set the publishing rate (adjust as needed)
  /*
  rclcpp::Rate rate(10.0);

  while (rclcpp::ok()) {
    rclcpp::spin_some(node);
    rate.sleep();
  }
  */
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}