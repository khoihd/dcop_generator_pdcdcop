#include <memory>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <set>
#include <iostream>
#include <limits>

#include "Instance/instance.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/constraint.hpp"
#include "Kernel/constraint_pdc.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/variable.hpp"

using namespace dcop_generator;
using namespace std;


instance::instance()
  : m_max_constraint_arity(2)
{ }


instance::~instance()
{ }


void instance::add_agents(std::vector<int> nodes) {
  for (int agent_id : nodes)
    instance::save(make_shared<agent>("a_" + std::to_string(agent_id)));
}


void instance::add_variables(std::vector<int> variables_id, int d_min, int d_max) {
  // for (int var_id : variables_id) {
  //   // int agent_id = m_vars_to_agents[var_id];
  //   std::string agent_name = "a" + std::to_string(var_id + 1);
  //   std::string var_name = "x" + std::to_string(var_id + 1);
  //   // instance::save(make_shared<domain>("d", d_min, d_max));
  //   // instance::save(make_shared<variable>(var_id + 1, var_name, "d", agent_name));
  //
  //   instance::save_decision_domain(make_shared<variable>(var_id + 1, var_name, "d", agent_name), make_shared<domain>("d", d_min, d_max));
  // }
}

void instance::add_decision_variables(std::vector<int> variables_id, int d_min, int d_max, graph input_graph) {
  for (int var_id : variables_id) {
    // int agent_id = m_vars_to_agents[var_id];
    std::string agent_name = "a" + std::to_string(var_id + 1);
    std::string var_name = "x" + std::to_string(var_id + 1);
    // instance::save(make_shared<domain>("d", d_min, d_max));
    // instance::save(make_shared<variable>(var_id + 1, var_name, "d", agent_name));

    variable::ptr decision = make_shared<variable>(var_id + 1, var_name, "d", agent_name);

    instance::save_decision_domain(decision, make_shared<domain>("d", d_min, d_max));
    instance::save_graph_degree(decision, input_graph.get_degree(var_id));
  }
}

void instance::add_random_variables(int random_variable_count, int d_min, int d_max) {
  for (int var_id = 0; var_id < random_variable_count; var_id++) {
    std::string agent_name = "a" + std::to_string(var_id + 1);
    std::string var_name = "y" + std::to_string(var_id + 1);

    instance::save_random_domain(make_shared<variable>(var_id + 1, var_name, "d", agent_name), make_shared<domain>("d", d_min, d_max));
  }
}

void instance::add_relation(int arity, double p2, int d_min, int d_max, std::string rel_name) {
//  int imin = -999999;

//  double p = ((double) rand() / (RAND_MAX));
  // probability of regular constraints
//  double equality_prob = 0.95;

  if (rel_name.length() == 0)
    rel_name = "r_" + std::to_string(arity);

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rnd(seed);

  uniform_int_distribution<cost_t> U_cost(0, 100);
  uniform_int_distribution<int> U_values(d_min, d_max);

  uniform_int_distribution<int> u_mult(1, 1);
  int alpha = u_mult(rnd); // To differentiate even more random utilities.

  int nb_values = (p2 * std::pow((d_max - d_min + 1), arity));

  relation::ptr rel = make_shared<relation>(rel_name, arity, 0, "soft");
  std::set<std::vector<int> > tuples;
  std::vector<int> tuple(arity);

  /* create values for each tuple */
  while (tuples.size() < nb_values) {
    for (int i = 0; i < arity; ++i)
      tuple[i] = U_values(rnd);
    tuples.insert(tuple);
  }

  /* add utility, and add <tuple, utility> to the relation */
  /* probability of regular constraint is equality_prob */
//  if (p < equality_prob) {
    for (std::vector<int> tuple : tuples) {
      rel->add_tuple(std::make_pair(tuple, alpha * U_cost(rnd)));
    }
//  }
  /* probability of having equality constraints is 1 - equality_prob */
/*  else {
    for (std::vector<int> tuple : tuples) {
      if (tuple[0] == tuple [1])
        rel->add_tuple(std::make_pair(tuple, 0));
      else
      rel->add_tuple(std::make_pair(tuple, imin));
    }
  }
*/
  instance::save(rel);
}

void instance::add_constraint(std::vector<int> variables_id, int arity, std::string rel_name) {

  if (rel_name.length() == 0)
    rel_name = "r_" + std::to_string(arity);

  std::vector<std::string> scope;
  for (int var_id : variables_id)
    scope.push_back("x_" + std::to_string(var_id + 1));

  int c_id = instance::m_constraint_with_name.size();
  instance::save(constraint::ptr(
          make_shared<constraint>("c_" + std::to_string(c_id), variables_id, scope, rel_name)));
}

void instance::add_constraint_pdcdcop(std::vector<variable::ptr> variables, int arity, std::string rel_name) {
  // if (rel_name.length() == 0)
  //   rel_name = "r_" + std::to_string(arity);

  // std::vector<std::string> scope;
  //
  // for (std::string var : variables) {
  //   scope.push_back(var);
  // }

  int c_id = instance::m_constraint_with_name.size();
  instance::save(constraint_pdc::ptr(make_shared<constraint_pdc>("c_" + std::to_string(c_id), variables, rel_name)));
}


std::string instance::to_string() const {

  std::string res;
  res += "Agents\n";
  for (const agent::ptr a : m_agents)
    res += a->to_string() + "\n";

  res += "\nDomains\n";
  for (const domain::ptr d : m_domains)
    res += d->to_string() + "\n";

  res += "\nVariables\n";
  for (const variable::ptr v : m_variables)
    res += v->to_string() + "\n";

  res += "\nConstraints\n";
  for (const constraint::ptr c : m_constraints)
    res += c->to_string() + "\n";

  res += "\nRelations\n";
  for (const relation::ptr r : m_relations)
    res += r->to_string() + "\n";

  return res;
}
