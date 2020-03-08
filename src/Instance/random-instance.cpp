#include "Graph/random-graph.hpp"
#include "Graph/graph-utils.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/variable.hpp"
#include "Instance/random-instance.hpp"
#include "utils.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

//#define ONEREL

random_instance::random_instance(int nb_agents, int nb_rands, int domain_size, int rand_dom_size, double p1_agents, double p2, int max_nb_neighbors,
                                 int max_constr_arity, int nb_local_variables, int max_nb_boundary_variables,
                                 double p1_local_variables) {
    instance::type = "random";
    this->setP1(p1_agents);
    this->setP2(p2);

    m_max_constraint_arity = max_constr_arity;

    random_graph graph(nb_agents, p1_agents, max_nb_neighbors);

    add_agents(graph.get_nodes());

    int nb_nodes = graph.get_nb_nodes();
    for (int n = 0; n < nb_nodes; ++n) {
        random_graph subgraph(nb_local_variables, p1_local_variables);

        int last_node = graph.get_nb_nodes();
        graph.join(subgraph, n, max_nb_boundary_variables);

        // Map new added Variables to agent
        m_vars_to_agents[n] = n;        // Map old variable to agent
        for (int i = last_node; i < graph.get_nb_edges(); ++i)
            m_vars_to_agents[i] = n;
    }

    add_variables(graph.get_nodes(), 0, domain_size - 1);
    add_random_variables(nb_rands, 0, rand_dom_size - 1);

    for (int k = max_constr_arity; k >= 3; k--) {
        vector<vector<int> > cliques = graph_utils::cliques(graph, k);
        if (!cliques.empty())
            add_relation(k, p2, 0, domain_size - 1);

        for (vector<int> nodes : cliques) {
            // Save Constraint of arity k
            add_constraint(nodes, k);

            // Remove edges from graph (all pairs in nodes)
            do {
                int u = nodes[0], v = nodes[1];
                graph.erase_edge(u, v);
            } while (utils::next_combination
                    (nodes.begin(), nodes.begin() + 2, nodes.end()));
        }
    }

    // Creates constraints for all the binary constraints left
    if (graph.get_nb_edges() > 0) {
#ifdef ONEREL
    std::string rel_name = "r2";
    add_relation(2, p2, 0, domain_size - 1, rel_name);
#endif

        std::vector<std::string> scope(2);
        for (int i = 0; i < graph.get_nb_nodes(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph.get_edge(i, j)) {
#ifndef ONEREL
                    scope[0] = "x_" + std::to_string(i);
                    scope[1] = "x_" + std::to_string(j);
                    std::string rel_name = "constraint" + scope[0] + "_" + scope[1];
                    add_relation(2, p2, 0, domain_size - 1, rel_name);
#endif
                    add_constraint_pdcdcop(scope, 2, rel_name);
                }
            }
        }
    }

}

random_instance::~random_instance()
{ }

std::string random_instance::to_string() const {
    return "random-network";
}
