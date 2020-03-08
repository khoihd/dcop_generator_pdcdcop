#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sstream>

#include "IO/output-max_sum.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/variable.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"


using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

output_maxsum::output_maxsum(std::string pathout, std::string fileout, int nb_instances, int nb_start)
  : output(pathout, fileout, nb_instances, nb_start)
{ }


void output_maxsum::to_string(instance::ptr instance) {
  output::to_string(instance);
}


void output_maxsum::to_string(instance::ptr instance, std::string file)
{
  size_t found = file.find_last_of(".");
  std::string extension = file.substr(found+1);
  if (found == std::string::npos)
    file += ".maxsum";
  else if ( extension.compare("maxsum") != 0 ){
    file = file.substr(0, found);
    file += ".maxsum";
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


void output_maxsum::dump_instance(std::ostream &os) {
  os << "AGENT 1" << std::endl;
}

void output_maxsum::dump_agents(std::ostream &os, std::vector<agent::ptr> agents, std::vector<domain::ptr> domains) {

  int agt_num = 0;
  std::stringstream ss_v;
  std::stringstream ss_d;
  domain_size = domains[ 0 ]->get_max() - domains[ 0 ]->get_min() + 1;
  for (agent::ptr agent : agents) {
    ss_v << agt_num++;
    ss_d << (domains[ 0 ]->get_max() - domains[ 0 ]->get_min() + 1);
    os << "VARIABLE"
       << space_ms << ss_v.str() << space_ms << "1"
       << space_ms << ss_d.str() << std::endl;
    ss_v.str ( std::string() );
    ss_d.str ( std::string() );
  }
}

void output_maxsum::dump_constraints(std::ostream &os, std::vector<constraint::ptr> constraints,
                                     std::vector<relation::ptr> relations) {
  
  int ** domain_vals = new int* [domain_size];
  for (int i = 0; i < domain_size; ++i) domain_vals[i] = new int[ domain_size ];
  
  int num = 1;
  std::stringstream ss_c;
  for (constraint::ptr con : constraints) {
    ss_c << num++;
    os << "CONSTRAINT " << ss_c.str() << space_ms << "1" << space_ms;
    ss_c.str ( std::string() );
    int i = 0;
    for ( std::string var : con->get_scope() ) {
      auto found = var.find_first_of ( "_" );
      os << var.substr ( found + 1, std::string::npos );
      if ( ++i < con->get_arity() ) os << " ";
    }
    os << std::endl;
    
    // Print constraint extensively
    for (int r = 0; r < relations.size(); r++) {
      if (con->get_relation() == (relations[ r ])->get_name()) {
        auto rel = relations[ r ];
        
        for (int i = 0; i < domain_size; ++i)
          for (int j = 0; j < domain_size; ++j) 
	    domain_vals[i][j] = -9999999;

        for (relation::relentry_t& entry : rel->get_tuples()) {
          domain_vals[entry.first[0]][entry.first[1]] = entry.second;
        }
        
        
        for (int i = 0; i < domain_size; ++i) {
          for (int j = 0; j < domain_size; ++j) {
            os << "F" << space_ms;
            os << i << space_ms << j << space_ms << domain_vals[i][j] << std::endl;
          }
        }
        
        /*
        for( Relation::relentry_t& entry : rel->tuples() ) {
          os << "F" << space_ms;
          for ( int value : entry.first ) { os << value << space_ms; }
          os << costToString ( entry.second ) << std::endl;
        }
        */
        break;
      }
    }//r
  }
  for (int i = 0; i < domain_size; ++i) delete domain_vals[i];
  delete domain_vals;
}
