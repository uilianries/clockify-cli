#include "clockify_cli.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>

#include <lyra/lyra.hpp>

#include "clockify_consumer.hpp"


std::string ClockifyCli::_parse_command(int argc, char** argv) {
    std::string command;
    auto cli = lyra::opt( _api_key, "api_key" )
              ["-k"]["--api_key"]
                      ("Clockify user's API key")
              | lyra::arg( command, "command" )
                      ("Which command to run");
    auto result = cli.parse({argc, argv});
    if (!result) {
        std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return command;
}

void ClockifyCli::process_get_user_info() {
    ClockifyConsumer consumer(_api_key);
    const auto response = consumer.get_user_info();
    std::ostringstream oss;
    oss << "name: " << response["name"] << std::endl;
    oss << "email: " << response["email"] << std::endl;
    oss << "status: " << response["status"] << std::endl;
    std::cout << oss.str();
}

void ClockifyCli::run(int argc, char** argv) {
    const std::string command = _parse_command(argc, argv);
    if (command == "user") {
        process_get_user_info();
    }
}

