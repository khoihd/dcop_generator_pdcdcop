#ifndef DCOP_GENERATOR_INSTANCE_INSTANCE_FACTORY_HPP
#define DCOP_GENERATOR_INSTANCE_INSTANCE_FACTORY_HPP

#include <string>
#include <vector>

#include "Instance/instance.hpp"

namespace dcop_generator {

    class instance_factory {
    public:
        static instance::ptr create(int argc, char *argv[]);
    };
}

#endif // DCOP_GENERATOR_INSTANCE_INSTANCE_FACTORY_HPP
