#include <zephyr.h>

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <rmw_microros/rmw_microros.h>
#include <microros_transports.h>
#include <std_msgs/msg/int32.h>

#include <logging/log.h>

#include <std_msgs/msg/header.h>
#include <rcl/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sensor_msgs/msg/laser_scan.h>
#include <micro_ros_utilities/type_utilities.h>
#include <stdbool.h>

#define MICRO_ROS_APP_STACK 16000
#define MICRO_ROS_APP_TASK_PRIO 5

LOG_MODULE_REGISTER(uros_transport, LOG_LEVEL_DBG);

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printk("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc);}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printk("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}

// Publishers
rcl_publisher_t publisher;

//Subscribers
rcl_subscription_t subscriber_laser;

// Node support
rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;
rclc_executor_t executor;

// Messages
sensor_msgs__msg__LaserScan msgsub_laser;
sensor_msgs__msg__LaserScan msgpub;

bool id_set = false;
int id = 0;
enum states
{
  WAITING_AGENT,
  AGENT_AVAILABLE,
  AGENT_CONNECTED,
  AGENT_DISCONNECTED
} state;

void uros_transport_task();

K_THREAD_DEFINE(uros_transport, MICRO_ROS_APP_STACK, uros_transport_task, NULL, NULL, NULL, MICRO_ROS_APP_TASK_PRIO, 0,
                0);



void sub_subscription_callback_laser(const void * msgin)
{  
  const sensor_msgs__msg__LaserScan * msg = (const sensor_msgs__msg__LaserScan *)msgin;
    if (msg == NULL) {
      printf("Callback: msg NULL\n");
    } else {
      printf("NEW LASERSCAN MESSAGE RECEIVED!\n");
      printf("The Size of the ranges is: %d\n", msg->ranges.size);
      printf("The Size of the intensities is: %d\n", msg->intensities.size);
      struct timespec ts;
      clock_gettime(CLOCK_REALTIME, &ts);
      printf("Current Timestamp: [%d s], [%d ns]\n", ts.tv_sec, ts.tv_nsec);

      sensor_msgs__msg__LaserScan__copy(msg, &msgpub);

      rcl_ret_t rc;     
      rc = rcl_publish(&publisher, &msgpub, NULL);
      if (rc == RCL_RET_OK) {
        printf("Published msg successfully\n");
      } else {
        printf("Error: Message could not be published\n");
      } 
    }
} 




/* Create allocator, support, pub, sub, executor for node if agent connection is successful */
bool create_entities()
{ 
  // Access and process environment variables
  if (!id_set) {
    const char *arg = getenv("ID");
    if (arg != NULL) {
      id = atoi(arg);
      printf("ID: %s\n", arg);
      id_set = true;
    }
  }
  allocator = rcl_get_default_allocator();

  // Init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // Node
  RCCHECK(rclc_node_init_default(&node, "uros_micro_sensor", "", &support));

  // QoS
  rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;

  // Allocate Memory for Receiving Message

  static micro_ros_utilities_memory_conf_t conf = {0};

  //conf.max_string_capacity = 488;
  //conf.max_ros2_type_sequence_capacity = 488;
  //conf.max_basic_type_sequence_capacity = 488;

  conf.max_string_capacity = 1024;
  conf.max_ros2_type_sequence_capacity = 1024;
  conf.max_basic_type_sequence_capacity = 1024;


  bool success_sub = micro_ros_utilities_create_message_memory(
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, LaserScan),
    &msgsub_laser,
    conf
  );

  if (success_sub) {
    printf("Successfully Allocated Memory For Sub \n");
  }


  // Publisher
  char pub_topic_name[50];
  snprintf(pub_topic_name, sizeof(pub_topic_name), "/microros/sensor%d/outside_scan", id);
  RCCHECK(rclc_publisher_init_default(&publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, LaserScan), pub_topic_name));


  // Subscriber
  char sub_topic_name[50]; 
  snprintf(sub_topic_name, sizeof(sub_topic_name), "/sensor%d/scan_reliable", id);
  //RCCHECK(rclc_subscription_init(&subscriber_laser, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, LaserScan), "/sensor1/outside_scan", &qos_profile));
  RCCHECK(rclc_subscription_init_default(&subscriber_laser, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, LaserScan), sub_topic_name));
  // Executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 3, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber_laser, &msgsub_laser, &sub_subscription_callback_laser, ON_NEW_DATA));

  return true;
}

/* Destroy allocator, support, pub, sub, executor for node if agent connection is
 * lost or unsuccessful */
bool destroy_entities()
{
  rmw_context_t* rmw_context = rcl_context_get_rmw_context(&support.context);
  (void)rmw_uros_set_context_entity_destroy_session_timeout(rmw_context, 0);

  RCCHECK(rcl_publisher_fini(&publisher, &node));
  RCCHECK(rcl_subscription_fini(&subscriber_laser, &node));
  RCCHECK(rclc_executor_fini(&executor));
  RCCHECK(rcl_node_fini(&node));
  RCCHECK(rclc_support_fini(&support));

  return true;
}

/* Main transport task for transmitting and receiving data. Functions include
 * monitoring the agent connection, pinging and reconnecting. */
void uros_transport_task()
{

  while (1)
  {
    switch (state)
    {
      case WAITING_AGENT:
        state = (RMW_RET_OK == rmw_uros_ping_agent(100, 1)) ? AGENT_AVAILABLE : WAITING_AGENT;
        LOG_INF("Waiting for uROS agent.\r\n");
        printf("Waiting for uROS agent.\r\n");
        k_msleep(1000);
        break;

      case AGENT_AVAILABLE:
        state = (true == create_entities()) ? AGENT_CONNECTED : WAITING_AGENT;
        if (state == WAITING_AGENT)
        {
          destroy_entities();
          LOG_INF("Destroyed entities.");
        }
        else
        {
          /* Agent has connected and entities created. */
          LOG_INF("Connected to uROS agent and created entities.\r\n");
          printf("Connected to uROS agent and created entities.\r\n");
        }
        break;

      case AGENT_CONNECTED:
        state = (RMW_RET_OK == rmw_uros_ping_agent(500, 1)) ? AGENT_CONNECTED : AGENT_DISCONNECTED;

        if (state == AGENT_CONNECTED)
        {
          rclc_executor_spin_some(&executor, RCL_MS_TO_NS(50)); // was 100
		      k_msleep(500); // was 1000
        }

        break;
      case AGENT_DISCONNECTED:
        LOG_INF("Disconnected from agent. Switching to waiting for uROS agent\r\n");
        printf("Disconnected from agent. Switching to waiting for uROS agent\r\n");
        destroy_entities();
        state = WAITING_AGENT;

        break;
      default:
        break;
    }
  }
}




void main(void)
{
  /* Setup custom transports for microros. */
  rmw_uros_set_custom_transport(MICRO_ROS_FRAMING_REQUIRED, (void*)&default_params, zephyr_transport_open,
                                zephyr_transport_close, zephyr_transport_write, zephyr_transport_read);

  state = WAITING_AGENT;


}