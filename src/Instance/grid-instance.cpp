#include <Graph/random-graph.hpp>
#include "Instance/instance.hpp"
#include "Instance/grid-instance.hpp"
#include "Graph/graph-utils.hpp"
#include "Graph/planar-graph.hpp"
#include "utils.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

// #define ONEREL

grid_instance::grid_instance(int nb_agents, int domain_size, double p2, int max_constr_arity, int max_nb_neighbors,
                             int nb_local_variables, int max_nb_boundary_variables, double p1_local_variables) {
    instance::type = "grid";
    planar_graph graph(nb_agents, max_nb_neighbors);

    add_agents(graph.get_nodes());

    int nb_nodes = graph.get_nb_nodes();

    double p1 = graph.get_nb_edges()/(double)(nb_nodes*(nb_nodes-1)/2);
    this->setP1(p1);
    this->setP2(p2);

    for (int n = 0; n < nb_nodes; ++n) {
//        random_graph subgraph(nb_local_variables, p1_local_variables);
//
//        int last_node = graph.get_nb_nodes();
//        graph.join(subgraph, n, max_nb_boundary_variables);

        // Map new added Variables to agent
        m_vars_to_agents[n] = n;        // Map old variable to agent
//        for (int i = last_node; i < graph.get_nb_edges(); ++i)
//            m_vars_to_agents[i] = n;
    }

    add_variables(graph.get_nodes(), 0, domain_size - 1);

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
        std::vector<int> scope(2);
        for (int i = 0; i < graph.get_nb_nodes(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph.get_edge(i, j)) {
#ifndef ONEREL
                    std::string rel_name = "r_" + std::to_string(i) + "_" + std::to_string(j);
                    add_relation(2, p2, 0, domain_size - 1, rel_name);
#endif
                    scope[0] = i;
                    scope[1] = j;
                    add_constraint(scope, 2, rel_name);
                }
            }
        }
    }
}

std::string grid_instance::to_string() const {
    return "regular-grid";
}
