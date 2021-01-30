#include "clockify_consumer.hpp"

#include <cpr/cpr.h>


const std::string ClockifyConsumer::API_ENDPOINT = "https://api.clockify.me/api/v1";

ClockifyConsumer::ClockifyConsumer(const std::string& api_key)
: _api_key(api_key)
{
}

nlohmann::json ClockifyConsumer::get_user_info() {
    const std::string url = API_ENDPOINT + "/user";
    cpr::Response response = cpr::Get(cpr::Url{url},
                                      cpr::Header{{"accept", "application/json"}, {"X-Api-Key", _api_key}});
    return nlohmann::json::parse(response.text);
}

