#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "clockify_consumer.hpp"


TEST_CASE("Get user info", "[user]" ) {
    consumer = ClockifyConsumer("YBVVkGowgCBtyfx3")
    const auto response = consumer.user_info()

    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}


