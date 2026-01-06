#include <thread>
#include <memory>
#include <curl/curl.h>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <chrono>
#include <ctime>

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace boost::property_tree;

class ServiceRegister
{
public:

  ServiceRegister(std::string configurationData);
  
  int registerService();
  int updateExpirationDay(int serviceId);
  int deleteService();

private:

  int servicePort;
  int serviceValidation;

  std::string serverAddrPort;
  std::string serviceData;
  std::string serviceAddress;
  std::string serviceDefinition;
  std::string serviceURI;
  std::string systemName;

  static const std::string httpSecure_NotSecure;
  static const std::string registrationURL;
  static const std::string elemintationURL;
  static const std::string alterationURL;
  

  std::string getNewExpirationDate();
  std::string getServiceDataWithEndOfValidation();

  static size_t callbackHTTP(void *content, size_t size, size_t members, std::string *buffer);  
  
};