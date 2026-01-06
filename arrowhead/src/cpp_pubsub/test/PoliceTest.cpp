#include <gtest/gtest.h>
#include "../include/cpp_pubsub/PoliceService.hpp"

// Função de inicialização do ROS2
class ROS2Environment : public ::testing::Environment {
public:
    virtual void SetUp() {
        rclcpp::init(0, nullptr);
    }

    virtual void TearDown() {
        rclcpp::shutdown();
    }
};

TEST(RSU, InvalidServiceFile){

    std::string servicePath = "cpp_pubsub/test/files/ServicePlice1.json";
    int period = 10;
    std::string registryServerName = "server";

    EXPECT_THROW(PoliceService(servicePath, period, registryServerName), boost::property_tree::json_parser::json_parser_error);
}

TEST(RSU, MissingParametersOnServiceFile){

    std::string servicePath = "cpp_pubsub/test/files/ServicePolice2.json";
    int period = 10;
    std::string registryServerName = "server";

    EXPECT_THROW(PoliceService(servicePath, period, registryServerName), boost::property_tree::ptree_bad_path);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new ROS2Environment);
    return RUN_ALL_TESTS();
}