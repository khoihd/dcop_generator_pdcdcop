//
// Created by ffiorett on 6/2/16.
//

#ifndef DCOP_GENERATOR_IO_OUTPUT_WCSP_HPP
#define DCOP_GENERATOR_IO_OUTPUT_WCSP_HPP

#include <string>

#include "IO/output.hpp"
#include "Instance/instance.hpp"

namespace dcop_generator
{
    class output_wcsp: public output
    {
    public:
        output_wcsp (std::string pathout, std::string fileout, int nb_instances, int nb_start = 0);

        virtual void to_string(instance::ptr instance) override;

        virtual void to_string(instance::ptr instance, std::string file) override;

    private:
        int domain_size = 0;
        void dump_instance(std::ostream &os, instance::ptr instance);
        void dump_domains(std::ostream &os, instance::ptr instance);
        void dump_constraints (std::ostream &os, std::vector<constraint::ptr> constraints,
                               std::vector<relation::ptr> relations );
        const std::string txt_d = "\"";
        const std::string sep = " ";
    };

}

#endif //DCOP_GENERATOR_IO_OUTPUT_WCSP_HPP
