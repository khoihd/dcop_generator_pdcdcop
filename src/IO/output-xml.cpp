#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <random>

#include "IO/output-xml.hpp"
#include "Instance/meeting_scheduling_instance.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/variable.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"
#include <boost/algorithm/string.hpp>
// #include <boost/algorithm/string.hpp>
// #include <boost/algorithm/string.hpp>

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

std::map<std::string, std::set<std::string>> neighborMap;
const float minUtility = 0.0;
const float maxUtility = 10.0;

const std::string INIT_PROBABILITY = "initial_distribution";
const std::string TRANSITION_FUNCTION = "transition";
const std::string GRAPH_DEGREE = "graph_degree";

output_xml::output_xml(std::string pathout, std::string fileout, int nb_instances, int nb_start)
    : output(pathout, fileout, nb_instances, nb_start)
{}

std::vector<double> uniformGenerator(int count) {
  std::mt19937 rng;
  rng.seed(std::random_device()());

  std::vector<double> probabilityDistribution;
  double sum = 0;
  double cummulative = 0;
  std::uniform_real_distribution<> uniformUtility(1, 100);
  std::vector<double> randomValues;

  for (int i = 0; i < count; i++) {
    double random_value = uniformUtility(rng);
    randomValues.push_back(random_value);
    sum += random_value;
  }

  for (int i = 0; i < count - 1; i++) {
    double probability = randomValues.at(i) / sum;
    probabilityDistribution.push_back(probability);
    cummulative += probability;
  }

  probabilityDistribution.push_back(1 - cummulative);

  return probabilityDistribution;
}

std::vector<constraint_pdc::ptr> createConstraintsFromRandoms(std::map<variable::ptr, domain::ptr> randomDomains, std::map<variable::ptr, domain::ptr> decisionDomains) {
  std::vector<constraint_pdc::ptr> randomConstraints;

  for (auto randomEntry : randomDomains) {
    auto randomVariable = randomEntry.first;
    for (auto decisionEntry : decisionDomains) {
      auto decisionVariable = decisionEntry.first;

      // match random and decision variables
      if (boost::replace_all_copy(randomVariable->get_name(), "y", " ") == boost::replace_all_copy(decisionVariable->get_name(), "x", " ")) {
        std::vector<variable::ptr> scope(2);
        scope.push_back(decisionVariable);
        scope.push_back(randomVariable);

        std::string rel_name = "constraint_" + decisionVariable->get_name() + "_" + randomVariable->get_name();
        // add_relation(2, p2, 0, domain_size - 1, rel_name);
        randomConstraints.push_back(make_shared<constraint_pdc>("c_", scope, rel_name));

        break;
      }
    }
  }

  return randomConstraints;
}

void output_xml::to_string(instance::ptr instance) {
    output::to_string(instance);
}

void output_xml::to_string(instance::ptr instance, std::string file) {
  // size_t found = file.find_last_of(".");
  // std::string extension = file.substr(found+1);
  // if (found == std::string::npos)
  //   file += ".dzn";
  // else if(extension.compare("dzn") != 0){
  //   file = file.substr(0, found);
  //   file += ".dzn";
  // }

  vector<string> splited_strings;
  boost::split(splited_strings, file, boost::is_any_of("/"));
  std::string instance_type = splited_strings.at(0);
  std::string instance_number =  splited_strings.at(1);

  int decision_domain, random_domain;

  for (auto const& entry : instance->get_decision_domains()) {
    decision_domain = entry.second->get_max() + 1;
    break;
  }

  for (auto const& entry : instance->get_random_domains()) {
    random_domain = entry.second->get_max() + 1;
    break;
  }

  std::string instance_rand_dec = "x" + std::to_string(instance->get_decision_domains().size()) + "_y" + std::to_string(instance->get_random_domains().size())
                                  + "_dx" + std::to_string(decision_domain) + "_dy" + std::to_string(random_domain);
  std::string path_out = instance_type + "_" + instance_rand_dec;
  misc_utils::utils::create_dir(path_out);

  std::string instance_file = path_out + "/" + "instance_" + instance_number + "_" + instance_rand_dec + ".dzn";

  // std::cout << "file is: " << file << std::endl;
  std::cout << "file is: " << instance_file << std::endl;

  std::ofstream os (instance_file.c_str());
  if(os.is_open() ) {
      map<variable::ptr, domain::ptr> joined_domains;
      joined_domains.insert(instance->get_decision_domains().begin(), instance->get_decision_domains().end());
      joined_domains.insert(instance->get_random_domains().begin(), instance->get_random_domains().end());
      std::vector<constraint_pdc::ptr> randomConstraints = createConstraintsFromRandoms(instance->get_random_domains(), instance->get_decision_domains());

      dump_decision_variables(os, instance->get_decision_domains()); // decision1 = [0,1,2];
      dump_random_variables(os, instance->get_random_domains()); // random1 = [0,1,2];

      if (instance->to_string() == "random-network" || instance->to_string() == "grid-weather") {
        // dump_constraints_pdc(os, instance->get_constraints_pdc(), randomConstraints, joined_domains, false);
        dump_functions_pdc(os, instance->get_constraints_pdc(), randomConstraints, joined_domains, false);
      }
      else if (instance->to_string() == "meeting scheduling") {
        // dump_constraints_pdc(os, instance->get_constraints_pdc(), randomConstraints, joined_domains, true);
        dump_functions_pdc(os, instance->get_constraints_pdc(), randomConstraints, joined_domains, true);
      }
      
      // dump_initProb(os, instance->get_random_domains());
      // dump_transition(os, instance->get_random_domains());

      dump_initProb_continuous(os, instance->get_random_domains());
      dump_transition_continuous(os, instance->get_random_domains());

      dump_graph_degree(os, instance->get_graph_degree());
      dump_selfRandomCount(os);

      os.close();
  }
  else std::cout << "Cannot open file: " << instance_file << std::endl;
}

void output_xml::dump_decision_variables(std::ostream &os, std::map<variable::ptr, domain::ptr> domains) {
  for (auto const& entry : domains) {
    os << "decision_" << entry.first->get_name() << "=" << entry.second->to_string() << ";" << endl;
  }
}

void output_xml::dump_random_variables(std::ostream &os, std::map<variable::ptr, domain::ptr> domains) {
  for (auto const& entry : domains) {
    os << "random_" << entry.first->get_name() << "=" << entry.second->to_string() << ";" << endl;
  }
}

void output_xml::dump_functions_pdc(std::ostream &os, std::vector<constraint_pdc::ptr> decision_constraints, std::vector<constraint_pdc::ptr> random_constraints,
                                      std::map<variable::ptr, domain::ptr> joined_domains, bool isMeeting) {
  std::mt19937 rng;
  rng.seed(std::random_device()());

  std::uniform_real_distribution<> uniformUtility(minUtility, maxUtility);

  std::vector<constraint_pdc::ptr> joined_constraints;
  joined_constraints.insert(joined_constraints.end(), decision_constraints.begin(), decision_constraints.end());
  joined_constraints.insert(joined_constraints.end(), random_constraints.begin(), random_constraints.end());

  // TOOD: Stop here
  for (constraint_pdc::ptr con : joined_constraints) {
    std::string vars;
    std::set<std::string> neighborPair;
    for (variable::ptr var : con->get_scope()) {
      if (var == NULL) {
        continue;
      }

      vars.append(var->get_name());
      neighborPair.insert(var->get_name());
      vars.append(" ");
    }
    outputRandomFunction(os, vars.substr(0, vars.length() - 1));
    storeNeighbors(neighborPair);
    neighborPair.clear();
  }

  outputNeighborMap(os);
}

void output_xml::dump_constraints_pdc(std::ostream &os, std::vector<constraint_pdc::ptr> decision_constraints, std::vector<constraint_pdc::ptr> random_constraints,
                                      std::map<variable::ptr, domain::ptr> joined_domains, bool isMeeting) {
  std::mt19937 rng;
  rng.seed(std::random_device()());

  std::uniform_real_distribution<> uniformUtility(minUtility, maxUtility);

  std::vector<constraint_pdc::ptr> joined_constraints;
  joined_constraints.insert(joined_constraints.end(), decision_constraints.begin(), decision_constraints.end());
  joined_constraints.insert(joined_constraints.end(), random_constraints.begin(), random_constraints.end());

  for (constraint_pdc::ptr con : joined_constraints) {
    os << con->get_relation() << "=[" << endl;

    std::vector<std::vector<int>> domainList;

    for (variable::ptr var : con->get_scope()) {
      if (var != NULL) {
        domain::ptr variable_domain = NULL;
        for (auto const& entry : joined_domains) {
          if (entry.first->get_name() == var->get_name()) {
            variable_domain = entry.second;
            break;
          }
        }

        int minRange = variable_domain->get_min();
        int maxRange = variable_domain->get_max();

        std::vector<int> v(maxRange - minRange + 1);
        std::iota(std::begin(v), std::end(v), minRange);
        domainList.push_back(v);
      }
    }

    // Assume binary functions
    for (int value1 : domainList.front()) {
      for (int value2 : domainList.back()) {
        if (!isMeeting || (isMeeting && (value1 != value2))) {
          os << std::setprecision(2) << value1 << "," << value2 << "," << uniformUtility(rng) << "|" << endl;
        }
      }
    }

    os << "];" << endl;
  }

  // outputRandomFunction(os, vars.substr(0, vars.length() - 1));
  // storeNeighbors(neighborPair);
}

void output_xml::dump_initProb(std::ostream &os, std::map<variable::ptr, domain::ptr> domains) {
  for (auto const& entry : domains) {
    os << INIT_PROBABILITY << "_" << entry.first->get_name() << "=[";

    int dom_size = entry.second->get_max() - entry.second->get_min() + 1;
    std::vector<double> probabilityDistribution = uniformGenerator(dom_size);

    for (int i = 0; i < dom_size - 1; i++) {
      // cout << probabilityDistribution.at(i) << ",";
      os << probabilityDistribution.at(i) << ",";
    }
    os << probabilityDistribution.at(dom_size - 1) << "];" << endl;
  }
}

// Dump alpha and beta coefficients in Beta distribution
void output_xml::dump_initProb_continuous(std::ostream &os, std::map<variable::ptr, domain::ptr> domains) {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  // std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10); // distribution in range [1, 10]
  std::uniform_real_distribution<> dist10(4, 10); // distribution in range [1, 10]

  for (auto const& entry : domains) {
    // initial_distribution_y1=[alpha=2,beta=10]
    os << INIT_PROBABILITY << "_" << entry.first->get_name() << "=[";
    os << "alpha:" << dist10(rng) << ",beta:" << dist10(rng);
    os << "];" << endl;
  }
}

void output_xml::dump_transition_continuous(std::ostream &os, std::map<variable::ptr, domain::ptr> domains) {
  std::mt19937 rng;
  rng.seed(std::random_device()());
  // std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10); // distribution in range [1, 10]
  std::uniform_real_distribution<> dist10(4, 10); // distribution in range [1, 10]

  for (auto const& entry : domains) {
    // transition_y1=[alpha=2]
    os << TRANSITION_FUNCTION << "_" << entry.first->get_name() << "=[";
    os << "alpha:" << dist10(rng);
    os << "];" << endl;
  }
}

void output_xml::dump_transition(std::ostream &os, std::map<variable::ptr, domain::ptr> domains) {
  for (auto const& entry : domains) {
    os << TRANSITION_FUNCTION  << "_" << entry.first->get_name() << "=[" << endl;
    int dom_size = entry.second->get_max() - entry.second->get_min() + 1;

    for (int i = 0; i < dom_size; i++) {
      std::vector<double> probabilityDistribution = uniformGenerator(dom_size);

      for (int i = 0; i < dom_size - 1; i++) {
        // cout << probabilityDistribution.at(i) << ",";
        os << probabilityDistribution.at(i) << ",";
      }
      os << probabilityDistribution.at(dom_size - 1) << "|" << endl;
    }
    os << "];" << endl;
  }
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

void output_xml::dump_relations( std::ostream &os, std::vector<relation::ptr> relations) {
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

  os << "function(" << var1 << "," << var2 << ")=";
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

    // Do not print out the neighbor of random variables
    if (agent.find("y") != std::string::npos) {
      continue;
    }

    os << "neighbor_set_" << agent << "=";
    for (std::string neighbor : mapEntry.second) {
      os << neighbor << " ";
    }
    os << ";" << endl;
  }
  neighborMap.clear();
}

void output_xml::dump_graph_degree(std::ostream &os, std::map<variable::ptr, int> graph_degree) {
  // for (auto entry : graph_degree) {
  //   os << GRAPH_DEGREE << "_" << entry.first->get_name() << "=" << entry.second << ";" << endl;
  // }
}

void output_xml::dump_selfRandomCount(std::ostream &os) {

}

void output_xml::dump_instance(std::ostream &os) {
}

void output_xml::dump_agents(std::ostream &os, std::vector<agent::ptr> agents) {
}
