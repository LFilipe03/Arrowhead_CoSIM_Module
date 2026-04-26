#include "artery/ros2/CloudNode.h"
#include <nlohmann/json.hpp>
#include <omnetpp.h>

using namespace omnetpp;
using json = nlohmann::json;

namespace artery
{

Define_Module(CloudNode);

static size_t curlWriteCallback(void* contents, size_t size, size_t nmemb, std::string* output)
{
    output->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

CloudNode::CloudNode()
    : rosNode(Ros2Node::getInstance())
{
}

void CloudNode::initialize()
{
    publisher_ = rosNode.getRosNode()->create_publisher<arrowhead_msgs::msg::ArrowheadResponse>(
        "arrowhead_response", 10);

    EV_INFO << "CloudNode initialized, publishing to /arrowhead_response\n";
}

void CloudNode::handleMessage(cMessage* msg)
{
    delete msg;
}

void CloudNode::handleRequest(const std::string& carId)
{
    Enter_Method_Silent("handleRequest");

    EV_INFO << "CloudNode: requesting orchestration for " << carId << "\n";

    std::string responseStr = requestOrchestration(carId);
    if (responseStr.empty()) {
        EV_ERROR << "CloudNode: orchestration HTTP call failed for " << carId << "\n";
        return;
    }

    try {
        auto j = json::parse(responseStr);
        auto& providers = j["response"];

        if (providers.empty()) {
            EV_WARN << "CloudNode: no providers returned for " << carId << "\n";
            return;
        }

        auto& first = providers[0];
        std::string providerName = first["provider"]["systemName"];
        std::string providerAddress = first["provider"]["address"];
        int providerPort = first["provider"]["port"];
        std::string serviceUri = first["serviceUri"];
        std::string serviceDef = first["service"]["serviceDefinition"];

        arrowhead_msgs::msg::ArrowheadResponse response;
        response.system_name = carId;
        response.service_definition = serviceDef;
        response.result = "OK - " + providerName + " at " + providerAddress +
                          ":" + std::to_string(providerPort) + serviceUri;

        publisher_->publish(response);

        EV_INFO << "CloudNode: " << carId << " authorized -> " << response.result << "\n";

    } catch (const std::exception& e) {
        EV_ERROR << "CloudNode: failed to parse orchestration response: " << e.what() << "\n";
    }
}

std::string CloudNode::requestOrchestration(const std::string& carId)
{
    json body = {
        {"requesterSystem", {
            {"systemName", carId},
            {"address", "127.0.0.1"},
            {"port", 9002}
        }},
        {"requestedService", {
            {"serviceDefinitionRequirement", "traffic-information"},
            {"interfaceRequirements", {"HTTP-INSECURE-JSON"}},
            {"securityRequirements", {"NOT_SECURE"}}
        }},
        {"orchestrationFlags", {
            {"overrideStore", true}
        }}
    };

    std::string bodyStr = body.dump();
    std::string responseStr;

    CURL* curl = curl_easy_init();
    if (!curl) return "";

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8441/orchestrator/orchestration");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, bodyStr.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseStr);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    CURLcode res = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        EV_ERROR << "CloudNode: curl error: " << curl_easy_strerror(res) << "\n";
        return "";
    }

    return responseStr;
}

} // namespace artery
