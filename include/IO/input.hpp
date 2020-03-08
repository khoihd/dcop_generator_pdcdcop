#ifndef DCOP_GENERATOR_IO_INPUT_HPP
#define DCOP_GENERATOR_IO_INPUT_HPP

#include <cstring>
#include <iostream>
#include <stdlib.h>     /* atoi */
#include "utils.hpp"

namespace dcop_generator
{
    namespace input
    {
        int get_nb_instances(char *argv[]);

        std::string get_file_out(char *argv[]);

        int get_min_nb_arguments();

        std::string usage();

        void check_params(int argc, char *argv[]);

    }
}

#endif // DCOP_GENERATOR_IO_INPUT_HPP
