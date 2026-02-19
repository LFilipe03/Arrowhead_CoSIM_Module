#ifndef ROS2_SERVICEOBJECT_H_Q7PI0NHO
#define ROS2_SERVICEOBJECT_H_Q7PI0NHO

#include <omnetpp/cobject.h>
#include <string>
#include <vector>

namespace ros2
{

class ServiceObject : public omnetpp::cObject
{
public:
    ServiceObject();

    // Service validation
    void setServiceValidation(int v) { m_service_validation = v; }
    int getServiceValidation() const { return m_service_validation; }

    // Server address:port
    void setServerAddrPort(const std::string& addrport) { m_server_addrport = addrport; }
    const std::string& getServerAddrPort() const { return m_server_addrport; }

    // Service metadata
    void setServiceDefinition(const std::string& def) { m_service_definition = def; }
    const std::string& getServiceDefinition() const { return m_service_definition; }

    void setServiceURI(const std::string& uri) { m_service_uri = uri; }
    const std::string& getServiceURI() const { return m_service_uri; }

    void setVersion(int v) { m_version = v; }
    int getVersion() const { return m_version; }

    void setSecure(const std::string& s) { m_secure = s; }
    const std::string& getSecure() const { return m_secure; }

    void setInterfaces(const std::vector<std::string>& ifaces) { m_interfaces = ifaces; }
    const std::vector<std::string>& getInterfaces() const { return m_interfaces; }

    // Highway-related info
    void setHighwayName(const std::string& name) { m_highway_name = name; }
    const std::string& getHighwayName() const { return m_highway_name; }

    void setEntranceNumber(int n) { m_entrance_number = n; }
    int getEntranceNumber() const { return m_entrance_number; }

    // System / network info
    void setSystemName(const std::string& name) { m_system_name = name; }
    const std::string& getSystemName() const { return m_system_name; }

    void setAddress(const std::string& addr) { m_address = addr; }
    const std::string& getAddress() const { return m_address; }

    void setPort(int p) { m_port = p; }
    int getPort() const { return m_port; }

    void setAuthenticationInfo(const std::string& info) { m_authentication_info = info; }
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

#endif /* ROS2_SERVICEOBJECT_H_Q7PI0NHO */
