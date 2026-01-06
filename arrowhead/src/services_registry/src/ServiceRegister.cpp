#include "../include/services_registry/ServiceRegister.hpp"

const std::string ServiceRegister::httpSecure_NotSecure = "http://";
const std::string ServiceRegister::registrationURL = "/serviceregistry/register";
const std::string ServiceRegister::elemintationURL = "/serviceregistry/unregister";
const std::string ServiceRegister::alterationURL = "/serviceregistry/mgmt/";

size_t ServiceRegister::callbackHTTP(void *content, size_t size, size_t members, std::string *buffer){
  size_t totalSize = size * members;
  buffer->append((char*) content, totalSize);
  return totalSize;
}

ServiceRegister::ServiceRegister(std::string configurationData)
{

  try{

    ptree configurationFile;
    std::stringstream ss(configurationData);
    boost::property_tree::read_json(ss, configurationFile);

    std::cout << "[INFO] Configuration Opened" << std::endl;

    std::ostringstream oss;
    write_json(oss, configurationFile.get_child("serviceData"), true);

    serviceValidation = configurationFile.get<int>("serviceValidation");
    servicePort = configurationFile.get<int>("serviceData.providerSystem.port");

    serviceData = oss.str();

    serverAddrPort = configurationFile.get<std::string>("serverAddrPort");
    serviceAddress = configurationFile.get<std::string>("serviceData.providerSystem.address");
    serviceDefinition = configurationFile.get<std::string>("serviceData.serviceDefinition");
    serviceURI = configurationFile.get<std::string>("serviceData.serviceUri");
    systemName = configurationFile.get<std::string>("serviceData.providerSystem.systemName");

    std::cout << "[INFO] Configuration Read" << std::endl;

  }catch(const json_parser::json_parser_error& error){

    std::cerr << "[ERROR] Error opening Cofiguration File: " << error.what() << std::endl;
    std::terminate();
  
  }
}

int ServiceRegister::registerService(){

  CURL* curl;
  CURLcode response;
  std::string responseBuffer;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl){

    std::string completeURL = httpSecure_NotSecure + serverAddrPort + registrationURL;
    std::string serviceDataWithExpiration = getServiceDataWithEndOfValidation();
    
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, completeURL.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, serviceDataWithExpiration.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callbackHTTP);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    response = CURLE_FAILED_INIT;
    short tries = 0;
    bool success = true;

    while (response != CURLE_OK && tries < 3){

      std::cout << "[INFO] Trying to register service [" << tries << "]" << std::endl;

      response = curl_easy_perform(curl);
      tries++;

      if (response != CURLE_OK){

        std::cerr << "[ERROR] Error registering service: " << curl_easy_strerror(response) << std::endl;
        
        if (tries < 3){

          std::this_thread::sleep_for(std::chrono::seconds(5));

        }else {

          success = false;

        }
        
      }

    }

    if (!success){

      std::cerr << "[ERROR] Server Unreacheable" << std::endl;
      return -1;

    }else {

      long httpCode = 0;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

      std::cout << "[INFO] Response to service registration with code " << httpCode << ": " << responseBuffer << std::endl;

      switch(httpCode){
        case 201:
          std::cout << "[INFO] Service Registered" << std::endl;
          break;
        case 400:
          std::cerr << "[ERROR] Could not register service" << std::endl;
          break;
        case 401:
          std::cerr << "[ERROR] You are not authorized" << std::endl;
          break;
        case 500:
          std::cerr << "[ERROR] Core service is not available" << std::endl;
          break;
        default:
          std::cerr << "[ERROR] Service Registration Failed" << std::endl;
          break;
      }

      if (httpCode != 201){

        return -1;

      }else {

        rapidjson::Document document;
        document.Parse(responseBuffer.c_str());
        int serviceId = document["id"].GetInt();
        std::cout << "[INFO] Service ID: " << serviceId << std::endl;
        return serviceId;

      }

    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

  }else {

    std::cerr << "[ERROR] Error Initiating CURL" << std::endl;
    curl_global_cleanup();

    return -1;

  }

}

int ServiceRegister::updateExpirationDay(int serviceId){

  CURL* curl;
  CURLcode response;
  std::string responseBuffer;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl){

    std::string completeURL = httpSecure_NotSecure + serverAddrPort + alterationURL + std::to_string(serviceId);
    std::string serviceDataWithExpiration = getServiceDataWithEndOfValidation();

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, completeURL.c_str());
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, serviceDataWithExpiration.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callbackHTTP);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    response = CURLE_FAILED_INIT;
    short tries = 0;
    bool success = true;

    while (response != CURLE_OK && tries < 3){

      std::cout << "[INFO] Trying to update service's end of validation [" << tries << "]" << std::endl;

      response = curl_easy_perform(curl);
      tries++;

      if (response != CURLE_OK){

        std::cerr << "[ERROR] Error updating service's end of validation: " << curl_easy_strerror(response) << std::endl;
        
        if (tries < 3){

          std::this_thread::sleep_for(std::chrono::seconds(5));

        }else {

          success = false;

        }
        
      }

    }

    if (!success){

      std::cerr << "[ERROR] Server Unreacheable, please contact the System Administrator to update the service's end of validation" << std::endl;
      return -1;

    }else {

      long httpCode = 0;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

      std::cout << "[INFO] Response to service's end of validation alteration with code " << httpCode << ": " << responseBuffer << std::endl;

      switch(httpCode){
        case 200:
          std::cout << "[INFO] Service updated" << std::endl;
          break;
        case 400:
          std::cerr << "[ERROR] Could not update service" << std::endl;
          break;
        case 401:
          std::cerr << "[ERROR] You are not authorized" << std::endl;
          break;
        case 500:
          std::cerr << "[ERROR] Core service is not available" << std::endl;
          break;
        default:
          std::cerr << "[ERROR] Service's end of validation alteration Failed" << std::endl;
          break;
      }

      if (httpCode != 200){

        return -1;

      }

      return 0;

    }

    curl_easy_cleanup(curl);

  }else {

    std::cerr << "[ERROR] Error Initiating CURL" << std::endl;
    curl_global_cleanup();

    return -1;

  }

}

int ServiceRegister::deleteService(){

  CURL* curl;
  CURLcode response;
  std::string responseBuffer;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();

  if (curl){

    std::string startURL = httpSecure_NotSecure + serverAddrPort + elemintationURL;
    std::stringstream ss;
    ss << "?address=" << serviceAddress << "&port=" << servicePort << "&service_definition=" << serviceDefinition << "&service_uri=" << serviceURI << "&system_name=" << systemName;

    std::string completeURL = startURL + ss.str();

    curl_easy_setopt(curl, CURLOPT_URL, completeURL.c_str());
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callbackHTTP);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    response = CURLE_FAILED_INIT;
    short tries = 0;
    bool success = true;

    while (response != CURLE_OK && tries < 3){

      std::cout << "[INFO] Trying to remove service [" << tries << "]" << std::endl;

      response = curl_easy_perform(curl);
      tries++;

      if (response != CURLE_OK){

        std::cerr << "[ERROR] Error deleting service: " << curl_easy_strerror(response) << std::endl;
        
        if (tries < 3){

          std::this_thread::sleep_for(std::chrono::seconds(5));

        }else {

          success = false;

        }
        
      }

    }

    if (!success){

      std::cerr << "[ERROR] Server Unreacheable, please contact the System Administrator to remove the service" << std::endl;
      return -1;

    }else {

      long httpCode = 0;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

      std::cout << "[INFO] Response to service Elimination with code " << httpCode << ": " << responseBuffer << std::endl;

      switch(httpCode){
        case 200:
          std::cout << "[INFO] Registered service removed" << std::endl;
          break;
        case 400:
          std::cerr << "[ERROR] Could not remove service" << std::endl;
          break;
        case 401:
          std::cerr << "[ERROR] You are not authorized" << std::endl;
          break;
        case 500:
          std::cerr << "[ERROR] Core service is not available" << std::endl;
          break;
        default:
          std::cerr << "[ERROR] Service Elimination Failed" << std::endl;
          break;
      }

      if (httpCode != 200){

        return -1;

      }

      return 0;

    }

    curl_easy_cleanup(curl);

  }else {

    std::cerr << "[ERROR] Error Initiating CURL" << std::endl;
    curl_global_cleanup();

    return -1;

  }

}

std::string ServiceRegister::getNewExpirationDate(){

  auto currentTime = std::chrono::system_clock::now();
  std::chrono::hours hoursOfValidation(serviceValidation);

  auto expirationTime = currentTime + hoursOfValidation;

  std::time_t expirationTime_t = std::chrono::system_clock::to_time_t(expirationTime);
  std::tm localTime = *std::localtime(&expirationTime_t);

  std::stringstream ss;
  ss << std::put_time(&localTime, "%Y-%m-%dT%H:%M:%SZ");

  return ss.str();

}

std::string ServiceRegister::getServiceDataWithEndOfValidation(){

    rapidjson::Document document;
    document.Parse(serviceData.c_str());

    std::string expirationTime = getNewExpirationDate();
    rapidjson::Value endOfValidity;
    endOfValidity.SetString(expirationTime.c_str(), document.GetAllocator());

    document.AddMember("endOfValidity", endOfValidity, document.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();

}