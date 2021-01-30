#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream>

#include "clockify_consumer.hpp"


TEST_CASE("Get user info", "[user]" ) {
    ClockifyConsumer consumer("YBVVkGowgCBtyfx3");
    auto response = consumer.get_user_info();
    std::cout << "RESPONSE: " << response << std::endl;
    REQUIRE(response["status"] == "ACTIVE");
}


