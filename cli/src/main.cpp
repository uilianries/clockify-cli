#include <cstdlib>

#include "clockify_cli.hpp"

int main(int argc, char** argv) {
    ClockifyCli cli;
    cli.run(argc, argv);

    return EXIT_SUCCESS;
}
