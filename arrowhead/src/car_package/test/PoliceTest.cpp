#include <gtest/gtest.h>
#include "../include/car_package/PoliceService.hpp"

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

TEST(Vehicle, InvalidBaseFile){

    std::string carPath = "car_package/test/files/CarPath1.json";
    std::string baseConfPath = "car_package/test/fies/ServicesPolice1.json";
    std::string discoveryServerName = "server";

    EXPECT_THROW(PoliceService(carPath, baseConfPath, discoveryServerName), boost::property_tree::json_parser::json_parser_error);
}

TEST(Vehicle, InvalidPathFile){

    std::string carPath = "car_package/test/files/Carath1.json";
    std::string baseConfPath = "car_package/test/files/ServicesPolice1.json";
    std::string discoveryServerName = "server";

    EXPECT_THROW(PoliceService(carPath, baseConfPath, discoveryServerName), boost::property_tree::json_parser::json_parser_error);
}

TEST(Vehicle, MissingParametersOnPathFile){

    std::string carPath = "car_package/test/files/CarPath2.json";
    std::string baseConfPath = "car_package/test/files/ServicesPolice1.json";
    std::string discoveryServerName = "server";

    EXPECT_THROW(PoliceService(carPath, baseConfPath, discoveryServerName), boost::property_tree::ptree_bad_path);
}

TEST(Vehicle, MissingParametersOnBaseFile){

    std::string carPath = "car_package/test/files/CarPath1.json";
    std::string baseConfPath = "car_package/test/files/ServicesPolice2.json";
    std::string discoveryServerName = "server";

    EXPECT_NO_THROW(PoliceService(carPath, baseConfPath, discoveryServerName));
}

TEST(Vehicle, ValidFilesWithAllParameters){

    std::string carPath = "car_package/test/files/CarPath1.json";
    std::string baseConfPath = "car_package/test/files/ServicesPolice1.json";
    std::string discoveryServerName = "server";

    EXPECT_NO_THROW(PoliceService(carPath, baseConfPath, discoveryServerName));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new ROS2Environment);
    return RUN_ALL_TESTS();
}