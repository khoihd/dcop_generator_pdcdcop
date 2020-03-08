#include <fstream>
#include <sstream>
#include <vector>
#include "string_utils.hpp"
#include "Kernel/constraint.hpp"
#include "IO/output-topology.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

output_topology::output_topology(std::string pathout, std::string fileout, int nb_instances, int nb_start)
  : output(pathout, fileout, nb_instances, nb_start)
{ }


void output_topology::to_string(instance::ptr instance) {
  output::to_string(instance);
}

void output_topology::to_string(instance::ptr instance, std::string file) {

  size_t found = file.find_last_of(".");
  std::string extension = file.substr(found+1);
  if (found == std::string::npos)
    file += ".topo";
  else if ( extension.compare("topo") != 0 ){
    file = file.substr(0, found);
    file += ".topo";
  }

  std::cout << "file is: " << file << std::endl; 
  
  std::ofstream os ( file.c_str() );
  if( os.is_open() )
  {
    dump_topology( os, instance);
    os.close();
  }
  else std::cout << "Cannot open file: " << file << std::endl;
}


void output_topology::dump_topology(std::ostream &os, instance::ptr pInstance) {

  os << "instance " << pInstance->to_string() << " N.Agents= " << pInstance->get_agents().size()
          << " N.Variables= " << pInstance->get_variables().size()
          << " p1= " << pInstance->getP1()
          << " p2= " << pInstance->getP2() << "\n";

  for (constraint::ptr con : pInstance->get_constraints()) {
    for (int i=0; i<con->get_arity(); ++i) {
      if(i != con->get_arity()-1)
        os << con->get_scope()[i] << m_space_topo;
      else
        os << con->get_scope()[i] << "\n";
    }
  }
}