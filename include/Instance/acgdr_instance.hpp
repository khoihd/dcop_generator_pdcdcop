//
// Created by Ferdinando Fioretto on 11/8/15.
//

#ifndef DCOP_GENERATOR_ACGDR_INSTANCE_H
#define DCOP_GENERATOR_ACGDR_INSTANCE_H


#include <map>
#include <string>
#include <vector>

#include "Instance/instance.hpp"

namespace dcop_generator {
    class acgdr_instance : public instance {
    public:
        typedef std::shared_ptr<acgdr_instance> ptr;
        //acgdr_instance(int nb_bus, int nb_generators, int nb_loads, int domain_size, double p1);

    protected:
        virtual std::string to_string() const override;
    };
}

#endif //DCOP_GENERATOR_ACGDR_INSTANCE_H
