#ifndef CLOCKIFY_CLI_CLI_HPP
#define CLOCKIFY_CLI_CLI_HPP

#include <string>


class ClockifyCli {
public:
    void run(int argc, char** argv);

private:
    std::string _parse_command(int argc, char** argv);

    void process_get_user_info();

    std::string _api_key;
};


#endif //CLOCKIFY_CLI_CLI_HPP
