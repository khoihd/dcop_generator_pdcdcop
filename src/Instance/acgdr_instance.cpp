//
// Created by Ferdinando Fioretto on 11/8/15.
//

#include <utils.hpp>
#include "Instance/instance.hpp"
#include "Instance/acgdr_instance.hpp"
#include "Graph/graph-utils.hpp"
#include "Graph/random-graph.hpp"
#include "Graph/scale-free-graph.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

/*
acgdr_instance::acgdr_instance(int nb_bus, int nb_generators, int nb_loads, int domain_size, double p1)
{
    this->setP1(p1);

    m_max_constraint_arity = 2;
    int max_nb_neighbors = 0;
    random_graph graph(nb_bus, p1, max_nb_neighbors);

    add_agents(graph.get_nodes());

    int nb_nodes = graph.get_nb_nodes();
    for (int n = 0; n < nb_nodes; ++n) {
        m_vars_to_agents[n] = n;
    }

    add_variables(graph.get_nodes(), 0, domain_size - 1);

    // Creates constraints for all the binary constraints
    if (graph.get_nb_edges() > 0)
    {
        std::vector<int> scope(2);
        for (int i = 0; i < graph.get_nb_nodes(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph.get_edge(i, j)) {
                    std::string rel_name = "r_" + std::to_string(i) + "_" + std::to_string(j);
                    add_relation(2, p2, 0, domain_size - 1, rel_name);
                    scope[0] = i;
                    scope[1] = j;
                    add_constraint(scope, 2, rel_name);
                }
            }
        }
    }

}
*/
