#include <ros2/ServiceObject.h>

#include <string>
#include <vector>
#include <omnetpp.h>
#include <cmath>
#include <limits>

#include <rclcpp/rclcpp.hpp>


namespace ros2
{

class ServiceObject : public omnetpp::cObject
{
public:
    ServiceObject();

    void setServiceValidation(int v) { m_service_validation = v; }
    int getServiceValidation() const { return m_service_validation; }

    void setServerAddrPort(const std::string& s) { m_server_addrport = s; }
    const std::string& getServerAddrPort() const { return m_server_addrport; }

    void setServiceDefinition(const std::string& s) { m_service_definition = s; }
    const std::string& getServiceDefinition() const { return m_service_definition; }

    void setServiceUri(const std::string& s) { m_service_uri = s; }
    const std::string& getServiceUri() const { return m_service_uri; }

    void setVersion(int v) { m_version = v; }
    int getVersion() const { return m_version; }

    void setSecure(const std::string& s) { m_secure = s; }
    const std::string& getSecure() const { return m_secure; }

    void setInterfaces(const std::vector<std::string>& i) { m_interfaces = i; }
    const std::vector<std::string>& getInterfaces() const { return m_interfaces; }

    void setHighwayName(const std::string& h) { m_highway_name = h; }
    const std::string& getHighwayName() const { return m_highway_name; }

    void setEntranceNumber(int e) { m_entrance_number = e; }
    int getEntranceNumber() const { return m_entrance_number; }

    void setSystemName(const std::string& s) { m_system_name = s; }
    const std::string& getSystemName() const { return m_system_name; }

    void setAddress(const std::string& a) { m_address = a; }
    const std::string& getAddress() const { return m_address; }

    void setPort(int p) { m_port = p; }
    int getPort() const { return m_port; }

    void setAuthenticationInfo(const std::string& a) { m_authentication_info = a; }
    const std::string& getAuthenticationInfo() const { return m_authentication_info; }

private:
    int m_service_validation;
    std::string m_server_addrport;

    std::string m_service_definition;
    std::string m_service_uri;
    int m_version;
    std::string m_secure;
    std::vector<std::string> m_interfaces;

    std::string m_highway_name;
    int m_entrance_number;

    std::string m_system_name;
    std::string m_address;
    int m_port;
    std::string m_authentication_info;
};

} // namespace ros2

