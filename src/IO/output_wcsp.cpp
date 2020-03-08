#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sstream>

#include "IO/output-wcsp.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/variable.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"


using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

output_wcsp::output_wcsp(std::string pathout, std::string fileout, int nb_instances, int nb_start) 
        : output(pathout, fileout, nb_instances, nb_start)
{ }


void output_wcsp::to_string(instance::ptr instance) {
    output::to_string(instance);
}


void output_wcsp::to_string(instance::ptr instance, std::string file)
{
    size_t found = file.find_last_of(".");
    std::string extension = file.substr(found+1);
    if (found == std::string::npos)
        file += ".wcsp";
    else if ( extension.compare("wcsp") != 0 ){
        file = file.substr(0, found);
        file += ".wcsp";
    }

    std::cout << "file is: " << file << std::endl;

    std::ofstream os ( file.c_str() );
    if( os.is_open() ) {
        dump_instance(os, instance);
        dump_domains(os, instance);
        dump_constraints(os, instance->get_constraints(), instance->get_relations());
        os.close();
    }
    else std::cout << "Cannot open file: " << file << std::endl;

}


void output_wcsp::dump_instance(std::ostream &os, instance::ptr instance) {
    size_t maxDomSize = 0;
    for (auto d : instance->get_domains()) {
        maxDomSize = std::max(maxDomSize, d->get_size());
    }

    os  << instance->get_type() << "-" << output::get_curr_instance() << sep
        << instance->get_variables().size() << sep
        << maxDomSize << sep
        << instance->get_constraints().size() << sep
        << std::numeric_limits<int>::max()
        << std::endl;
}

void output_wcsp::dump_domains(std::ostream &os, instance::ptr instance) {
    for (auto v: instance->get_variables()) {
        for (auto d: instance->get_domains()) {
            if (v->get_domain() == d->get_name()) {
                os << d->get_size() << sep;
                break;
            }
        }
    }
    os << std::endl;
}

void output_wcsp::dump_constraints(std::ostream &os,
                                   std::vector<constraint::ptr> constraints,
                                   std::vector<relation::ptr> relations) {

    for (auto con : constraints) {
        relation::ptr rel = nullptr;
        for (auto r : relations) {
            if (r->get_name() == con->get_relation()) {
                rel = r;
                break;
            }
        }
        assert(rel != nullptr);

        os << con->get_arity() << sep;
        for (auto id: con->get_scope_id())
            os << id << sep;
        os << rel->get_default_cost() << sep << rel->get_nb_tuples() << std::endl;

        for (auto &entry : rel->get_tuples()) {
            for (auto id : entry.first)
                os << id << sep;
            os << entry.second << std::endl;
        }
    }
}
