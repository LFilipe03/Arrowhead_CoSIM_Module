#include "../include/services_discovery/ServiceDiscover.hpp"


ServiceDiscover::ServiceDiscover(const std::string& configurationFile)
{

  ptree configurationData;
  std::stringstream ss(configurationFile);
  
  try {

    boost::property_tree::read_json(ss, configurationData);
    std::cout << "[INFO] Base Configuration File read" << std::endl;

  } catch (const boost::property_tree::json_parser_error& e) {

    std::cerr << "Erro ao analisar a string base JSON: " << e.what() << std::endl;
    std::terminate();
    
  }
  //json_parser::read_json(configurationFile, configurationData);

  serviceRegistryAddrPort = configurationData.get<std::string>("serverAddrPort");

  std::ostringstream oss;
  write_json(oss, configurationData.get_child("serviceQueryData"), true);
  std::string queryBaseDataString = oss.str();
  queryBaseData = nlohmann::json::parse(queryBaseDataString);
}

std::vector<std::string> ServiceDiscover::getTopicNamesOfCloseServices(const std::vector<std::string>& servicesToFind){

  std::string closeServices = serviceDiscovery(servicesToFind);
  
  std::vector<std::string> topicNames;

  if (closeServices == ""){
    return topicNames;
  }
  
  nlohmann::json jsonServicesInfo = nlohmann::json::parse(closeServices);
  auto results = jsonServicesInfo["results"];

  for (auto queryService : results){

    auto servicesAvailable = queryService["serviceQueryData"]; 

    for (auto service : servicesAvailable){

      topicNames.push_back(service["serviceUri"]);
      std::cout << "[INFO] Service found: " << service["serviceUri"] << std::endl;
      
    }

  }

  return topicNames;

}

std::string ServiceDiscover::buildQueryData(const std::vector<std::string>& servicesToFind){
  
    nlohmann::json finalQueryData;
    finalQueryData["forms"] = nlohmann::json::array();

    for (auto service : servicesToFind){

      nlohmann::json serviceQuery = queryBaseData;
      serviceQuery["metadataRequirements"] = nlohmann::json::parse(service);
      finalQueryData["forms"].push_back(serviceQuery);

    }
    
    return finalQueryData.dump();
  
}

std::string ServiceDiscover::serviceDiscovery(const std::vector<std::string>& servicesToFind){

  CURL* curl;
  CURLcode response;
  std::string responseBuffer;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl){

    std::string registrationURL = httpSecure_NotSecure + serviceRegistryAddrPort + queryURL;
    std::string serviceData = buildQueryData(servicesToFind);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, registrationURL.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, serviceData.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callbackDiscovery);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
    
    response = CURLE_FAILED_INIT;
    short tries = 0;
    bool success = true;

    while (response != CURLE_OK && tries < 3){

      std::cout << "[INFO] Trying to search for services [" << tries << "]" << std::endl;

      response = curl_easy_perform(curl);
      tries++;

      if (response != CURLE_OK){

        std::cerr << "[ERROR] Error searching for services: " << curl_easy_strerror(response) << std::endl;
        
        if (tries < 3){

          std::this_thread::sleep_for(std::chrono::seconds(2));

        }else {

          success = false;

        }
        
      }

    }

    if (!success){

      std::cerr << "[ERROR] Server Unreacheable" << std::endl;
      curl_slist_free_all(headers);
      curl_easy_cleanup(curl);

      return "";

    }else {

      long httpCode = 0;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

      std::cout << "[INFO] Response to service's search with code " << httpCode << ": " << responseBuffer << std::endl;

      switch(httpCode){
        case 200:
          std::cout << "[INFO] Service Registry data returned" << std::endl;
          break;
        case 400:
          std::cerr << "[ERROR] Could not query Service Registry" << std::endl;
          break;
        case 401:
          std::cerr << "[ERROR] You are not authorized" << std::endl;
          break;
        case 500:
          std::cerr << "[ERROR] Core service is not available" << std::endl;
          break;
        default:
          std::cerr << "[ERROR] Search for Services Failed" << std::endl;
          break;
      }

      if (httpCode != 200){

        return "";

      }

      curl_slist_free_all(headers);
      curl_easy_cleanup(curl);

      return responseBuffer;

    }

  }else {

    std::cerr << "Error Initiating CURL";
    curl_global_cleanup();
    return "";

  }
}

size_t ServiceDiscover::callbackDiscovery(void *content, size_t size, size_t members, std::string *buffer){

    size_t totalSize = size * members;
    buffer->append((char*) content, totalSize);
    return totalSize;

}