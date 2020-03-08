#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <random>
#include <boost/range/combine.hpp>

#include "IO/output-xml.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/variable.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"


using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

std::map<std::string, std::set<std::string> > neighborMap;
const float minUtility = 0.0;
const float maxUtility = 10.0;

output_xml::output_xml(std::string pathout, std::string fileout, int nb_instances, int nb_start)
    : output(pathout, fileout, nb_instances, nb_start)
{
}

void output_xml::to_string(instance::ptr instance) {
    output::to_string(instance);
}


void output_xml::to_string(instance::ptr instance, std::string file) {
  size_t found = file.find_last_of(".");
  std::string extension = file.substr(found+1);
  if (found == std::string::npos)
    file += ".dzn";
  else if(extension.compare("dzn") != 0){
    file = file.substr(0, found);
    file += ".dzn";
  }

  std::cout << "file is: " << file << std::endl;

  std::ofstream os ( file.c_str() );
  if( os.is_open() ) {
      dump_decision_variables(os, instance->get_decision_domains()); // decision1 = [0,1,2];
      dump_random_variables(os, instance->get_random_domains());      // random1 = [0,1,2];
      dump_constraints_pdc(os, instance->get_constraints_pdc());

      dump_functions_pdc(os, instance->get_constraints_pdc());
      dump_initProb(os, instance->get_random_variables());
      dump_transition(os, instance->get_randoms_variables());

      dump_neighborCount(os);
      dump_selfRandomCount(os);

      os.close();
  }
  else std::cout << "Cannot open file: " << file << std::endl;
}

void output_xml::dump_constraints_pdc(std::ostream &os, std::vector<constraint_pdc::ptr> constraints) {
  std::mt19937 rng;
  rng.seed(std::random_device()());

  std::uniform_real_distribution<> uniformUtility(minUtility, maxUtility);

  os << "constraint";
  for (constraint_pdc::ptr con : constraints) {
    string vars;
    std::set<std::string> neighborPair;
    for (const std::string& var : con->get_scope()) {
      os << "_" << var;
    }
    os << " = ["

    for (auto tup : boost::combine(a, b, c, a)) {    // <---
        int x, w;
        double y;
        std::string z;
        boost::tie(x, y, z, w) = tup;
        printf("%d %g %s %d\n", x, y, z.c_str(), w);
    }

    // zip values from domain
    // generate random utility
    // separate by ;

    os << "];"

    outputRandomFunction(os, vars.substr(0, vars.length() - 1));
    storeNeighbors(neighborPair);
    // neighborPair.clear();
  }
}

void output_xml::dump_initProb(std::ostream &os, std::vector<variable::ptr> agents) {
}

void output_xml::dump_transition(std::ostream &os, std::vector<variable::ptr> agents) {
}

void output_xml::dump_domains(std::ostream &os, std::vector<domain::ptr> domains) {
  os << "domain ";
  for (domain::ptr dom : domains) {
    os << dom->get_size();
  }
  os << ";";
  os << std::endl;
}

void output_xml::dump_variables(std::ostream &os, std::vector<variable::ptr> variables) {
}

void output_xml::dump_decision_variables(std::ostream &os, std::vector<variable::ptr> variables, std::vector<domain::ptr> domains) {
  std::vector<variable::ptr>::iterator variable = variables.begin();
  std::vector<domain::ptr>::iterator domain = domains.begin();

  for(; variable != variables.end() && domain != domains.end(); ++variable, ++domain) {
    os << (*variable)->get_name() << " = [" << (*domain)->get_min() << "..." << (*domain)->get_max() << "];" << endl;
  }
}

void output_xml::dump_random_variables(std::ostream &os, std::vector<variable::ptr> variables, std::vector<domain::ptr> domains) {
  std::vector<variable::ptr>::iterator variable = variables.begin();
  std::vector<domain::ptr>::iterator domain = domains.begin();

  for(; variable != variables.end() && domain != domains.end(); ++variable, ++domain) {
    os << (*variable)->get_name() << " = [" << (*domain)->get_min() << "..." << (*domain)->get_max() << "];" << endl;
  }
}

void output_xml::dump_relations( std::ostream &os, std::vector<relation::ptr> relations) {
}

void output_xml::dump_functions_pdc(std::ostream &os, std::vector<constraint_pdc::ptr> constraints) {
  for (constraint_pdc::ptr con : constraints) {
    string vars;
    std::set<std::string> neighborPair;
    for (const std::string& var : con->get_scope()) {
      vars.append(var);
      neighborPair.insert(var);
      vars.append(" ");
    }
    outputRandomFunction(os, vars.substr(0, vars.length() - 1));
    storeNeighbors(neighborPair);
    // neighborPair.clear();
  }
  outputNeighborMap(os);
}

void output_xml::outputRandomFunction(std::ostream &os, string str) {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  // std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10); // distribution in range [1, 10]
  std::uniform_real_distribution<> dist10(1, 10.0); // distribution in range [1, 10]
  std::uniform_int_distribution<std::mt19937::result_type> distSign(0, 1); // distribution in range [0, 1]

  string function = "";
  string delimiter = " ";
  string var1 = str.substr(0, str.find(delimiter));
  string var2 = str.substr(str.find(delimiter) + 1);

  os << "function ";
  if (distSign(rng) == 0) os << "-"; os << dist10(rng);
  // os << dist10(rng);
  os << var1 << "^2" << " ";
  if (distSign(rng) == 0) os << "-"; os << dist10(rng);
  // os << dist10(rng);
  os << var1 << " ";
  if (distSign(rng) == 0) os << "-"; os << dist10(rng);
  // os << dist10(rng);
  os << var2 << "^2" << " ";
  if (distSign(rng) == 0) os << "-"; os << dist10(rng);
  // os << dist10(rng);
  os << var2 << " ";
  if (distSign(rng) == 0) os << "-"; os << dist10(rng);
  // os << dist10(rng);
  os << var1 << var2 << " ";
  if (distSign(rng) == 0) os << "-"; os << dist10(rng);
  // os << dist10(rng);
  os << ";";
  os << endl;
}

void output_xml::storeNeighbors(std::set<std::string> neighborPair) {
  // iterate thorugh the set (assume n-ary functions => n-size set)
  // for each agent, add the rest of the agents to the list of neighbors
  std::set<std::string>::iterator it;
  for (it = neighborPair.begin(); it != neighborPair.end(); ++it) {
    std::set<std::string> neighborToAddToMap = neighborPair;
    std::string agent = *it;
    neighborToAddToMap.erase(agent);

    // the neighborMap contains the agent
    if (neighborMap.find(agent) != neighborMap.end()) {
      std::set<std::string> neighbors = neighborMap.at(agent);
      for (std::string neighbor : neighborToAddToMap) {
        neighbors.insert(neighbor);
      }
      neighborMap[ agent ] = neighbors;
    } else {
      neighborMap.insert ( std::pair<std::string,std::set<std::string> >(agent, neighborToAddToMap) );
    }
  }
}

void output_xml::outputNeighborMap(std::ostream &os) {
  for (auto const& mapEntry : neighborMap) {
    std::string agent = mapEntry.first;
    std::set<std::string> neighborSet = mapEntry.second;
    os << "neighbor set: " << agent << ": ";
    for (std::string neighbor : neighborSet) {
      os << neighbor << " ";
    }
    os << ";" << endl;
  }
  neighborMap.clear();
}


void output_xml::dump_neighborCount(std::ostream &os) {
}

void output_xml::dump_selfRandomCount(std::ostream &os) {

}

void output_xml::dump_instance(std::ostream &os) {
}

void output_xml::dump_agents(std::ostream &os, std::vector<agent::ptr> agents) {
}
