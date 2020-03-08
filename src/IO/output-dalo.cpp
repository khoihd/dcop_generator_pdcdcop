#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sstream>

#include "IO/output-dalo.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/variable.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"


using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

// KHOI: output_ieee(...)
output_dalo::output_dalo(std::string pathout, std::string fileout, int nb_instances, int nb_start)
  : output(pathout, fileout, nb_instances, nb_start)
{ }


void output_dalo::to_string(instance::ptr instance) {
  output::to_string(instance);
}

void output_dalo::to_string(instance::ptr instance, std::string file) {

  size_t found = file.find_last_of(".");
  std::string extension = file.substr(found+1);
  if (found == std::string::npos)
    file += ".dalo";
  else if ( extension.compare("dalo") != 0 ){
    file = file.substr(0, found);
    file += ".dalo";
  }
  
  std::cout << "file is: " << file << std::endl; 
  
  std::ofstream os ( file.c_str() );
  if( os.is_open() ) {
    dump_instance(os);
    dump_agents(os, instance->get_agents(), instance->get_domains());
    dump_constraints(os, instance->get_constraints(), instance->get_relations());
    os.close();
  }
  else std::cout << "Cannot open file: " << file << std::endl;
  
}


void output_dalo::dump_instance(std::ostream &os) {
}//dumpInstance

void output_dalo::dump_agents(std::ostream &os, std::vector<agent::ptr> agents, std::vector<domain::ptr> domains) {
  os << "AGENT " << agents.size() << std::endl;
  int agt_num = 0;
  std::stringstream ss_v;
  std::stringstream ss_d;
  domain_size = domains[0]->get_max() - domains[0]->get_min() + 1;
  for (agent::ptr agent : agents) {
    ss_v << agt_num++;
    ss_d << (domains[0]->get_max() - domains[0]->get_min() + 1);
    os << "VARIABLE"
    << space_dalo << ss_v.str() << space_dalo << ss_v.str()
    << space_dalo << ss_d.str() << std::endl;
    ss_v.str(std::string());
    ss_d.str(std::string());
  }
}

void output_dalo::dump_constraints(std::ostream &os, std::vector<constraint::ptr> constraints,
                                   std::vector<relation::ptr> relations) {

  std::vector<std::vector<int>> dom_values(domain_size);
  for (int i=0; i<domain_size; i++)  {
    dom_values[i].resize(domain_size);
  }

  for (constraint::ptr con : constraints) {

    os << "CONSTRAINT ";
    int i = 0;
    for ( std::string var : con->get_scope() ) {
      auto found = var.find_first_of ( "_" );
      os << var.substr ( found + 1, std::string::npos );
      if ( ++i < con->get_arity() ) os << " ";
    }
    os << std::endl;
    
    // Print constraint extensively
    for ( int r = 0; r < relations.size(); r++ ) {
      
      if ( con->get_relation() == (relations[ r ])->get_name() ) {
        auto rel = relations[ r ];

        for (int i=0; i<domain_size; i++)  {
          // std::fill(dom_values[i].begin(), dom_values[i].end(), rel->get_default_cost());
          std::fill(dom_values[i].begin(), dom_values[i].end(), -9999999);
        }
        for (relation::relentry_t& entry : rel->get_tuples()) {
          dom_values[entry.first[0]][entry.first[1]] = entry.second;
        }
        for (int i = 0; i < domain_size; ++i) {
          for (int j = 0; j < domain_size; ++j) {
            os << "F" << space_dalo;
            os << i << space_dalo << j << space_dalo << dom_values[i][j] << std::endl;
          }
        }

//        for (relation::relentry_t& entry : rel->get_tuples()) {
//          os << "F" << space_dalo;
//          for (int value : entry.first) { os << value << space_dalo; }
//          os << cost_to_string(entry.second) << std::endl;
//        }

        break;
      }
    }//r
  }
  
//  for (int i = 0; i < domain_size; ++i) delete domain_vals[i];
//  delete domain_vals;
}
