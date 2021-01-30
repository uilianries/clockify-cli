#ifndef CLOCKIFY_CONSUMER_HPP_
#define CLOCKIFY_CONSUMER_HPP_

#include <string>
#include <nlohmann/json.hpp>

class ClockifyConsumer {

public:

    /**
     * Create a new consumer instance, ready for request commands
     * @param api_key Clockify user's API key
     */
    ClockifyConsumer(const std::string& api_key);

    nlohmann::json get_user_info();


private:
    const std::string _api_key;

    static const std::string API_ENDPOINT;
};

#endif // CLOCKIFY_CONSUMER_HPP_