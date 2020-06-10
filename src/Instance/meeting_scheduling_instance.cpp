#include "Graph/random-graph.hpp"
#include "Graph/graph-utils.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/constraint.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/agent.hpp"
#include "Kernel/variable.hpp"
#include "Instance/meeting_scheduling_instance.hpp"
#include "utils.hpp"
#include "Kernel/constants.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;


meeting_scheduling_instance::meeting_scheduling_instance(int nb_meetings, int nb_rands, int meetings_times, int rand_dom_size, double p1, double p2) {
    instance::type = "meeting-scheduling";
    this->setP1(p1);
    this->setP2(p2);

    m_max_constraint_arity = 2;
    int max_nb_neighbors = 0;
    random_graph graph(nb_meetings, p1, max_nb_neighbors);

    add_agents(graph.get_nodes());

    int nb_nodes = graph.get_nb_nodes();
    for (int n = 0; n < nb_nodes; ++n) {
        m_vars_to_agents[n] = n;
    }

    add_variables(graph.get_nodes(), 0, meetings_times - 1);
    add_decision_variables(graph.get_nodes(), 0, meetings_times - 1, graph);
    add_random_variables(nb_rands, 0, rand_dom_size - 1);

    for (int k = m_max_constraint_arity; k >= 3; k--) {
        vector<vector<int> > cliques = graph_utils::cliques(graph, k);
        if (!cliques.empty())
            add_relation(k, p2, 0, meetings_times - 1, "clique_"+std::to_string(k));

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
        std::vector<int> scope(2);
        for (int i = 0; i < graph.get_nb_nodes(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (graph.get_edge(i, j)) {
                    // std::string rel_name = "r_" + std::to_string(i) + "_" + std::to_string(j);
                    // add_relation(2, p2, 0, meetings_times - 1, rel_name);
                    // scope[0] = i;
                    // scope[1] = j;
                    // add_constraint(scope, 2, rel_name);

                    // scope[0] = "x_" + std::to_string(i);
                    std::vector<variable::ptr> scope(2);

                    variable::ptr var_i = make_shared<variable>(i + 1, "x" + std::to_string(i + 1), "d", "a" + std::to_string(i + 1));
                    variable::ptr var_j = make_shared<variable>(j + 1, "x" + std::to_string(j + 1), "d", "a" + std::to_string(j + 1));
                    scope.push_back(var_i);
                    scope.push_back(var_j);
                    std::string rel_name = "constraint_" + var_i->get_name() + "_" + var_j->get_name();
                    // add_relation(2, p2, 0, domain_size - 1, rel_name);

                    add_constraint_pdcdcop(scope, 2, rel_name);
                }
            }
        }
    }

}

meeting_scheduling_instance::~meeting_scheduling_instance()
{ }

std::string meeting_scheduling_instance::to_string() const {
return "meeting scheduling";
}

void meeting_scheduling_instance::add_relation(int arity, double p2, int d_min, int d_max, string rel_name) {
    if (rel_name.length() == 0)
        rel_name = "r_" + std::to_string(arity);

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rnd(seed);

    uniform_int_distribution<cost_t> U_cost(1, 100);
    uniform_int_distribution<int> U_values(d_min, d_max);

    uniform_int_distribution<int> u_mult(1, 1);
    int alpha = u_mult(rnd); // To differentiate even more random utilities.

    int nb_values = (p2 * std::pow((d_max - d_min + 1), arity));
    constexpr cost_t inf = std::numeric_limits<int>::max();

    relation::ptr rel = make_shared<relation>(rel_name, arity, inf, "soft");
    std::set<std::vector<int> > tuples;
    std::vector<int> tuple(arity);

    while (tuples.size() < nb_values) {
        for (int i = 0; i < arity; ++i)
            tuple[i] = U_values(rnd);
        tuples.insert(tuple);
    }

    for (std::vector<int> tuple : tuples) {
        // Find value in tuple which are the same
        bool conflict = false;
        for (int i = 0; i < tuple.size(); i++) {
            for (int j=i+1; j < tuple.size(); j++) {
                if (tuple[i] == tuple[j]) {
                    conflict = true;
                    break;
                }
            }
        }
        if (!conflict)
            rel->add_tuple(std::make_pair(tuple, alpha * U_cost(rnd)));
    }

    instance::save(rel);}
