#include <memory>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <thread>
#include <chrono>

using namespace boost::property_tree;

class ServiceDiscover
{
public:

  ServiceDiscover(const std::string& configurationFile);

  std::vector<std::string> getTopicNamesOfCloseServices(const std::vector<std::string>& servicesToFind);

  private:

  std::string serviceRegistryAddrPort;
  nlohmann::json queryBaseData;

  const std::string httpSecure_NotSecure = "http://";
  const std::string queryURL = "/serviceregistry/query/multi";

  std::string buildQueryData(const std::vector<std::string>& servicesToFind);
  std::string serviceDiscovery(const std::vector<std::string>& servicesToFind);
  static size_t callbackDiscovery(void *content, size_t size, size_t members, std::string *buffer);

};
