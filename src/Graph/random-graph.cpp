#include "Graph/random-graph.hpp"
#include "Graph/graph-utils.hpp"
#include "utils.hpp"

using namespace dcop_generator;
using namespace std;
using namespace misc_utils;

random_graph::random_graph(int nb_nodes, double p1, string topology_type, int max_nb_neighbors)
  : graph(nb_nodes) {

	if (max_nb_neighbors == 0)
		max_nb_neighbors = nb_nodes;

	unsigned seed =
			chrono::system_clock::now().time_since_epoch().count();
	p_rand = unique_ptr<default_random_engine>(new default_random_engine(seed));

	int max_nb_edges = (nb_nodes * (nb_nodes - 1)) / 2;
	int nb_edges = std::ceil(p1 * max_nb_edges);
	utils::massert(nb_edges >= nb_nodes - 1, "The graph connectivity " + std::to_string(p1)
	                                        + "cannot ensure a connected graph.");

	// Generates random edges
	uniform_int_distribution<int> U(0, nb_nodes - 1);
	int nb_nodes2 = nb_nodes * nb_nodes;

	while (!graph_utils::connected(*this)) {
		graph::clear();
		while (get_nb_edges() != nb_edges) {
			int fails = 0;
			int u, v;
			do {
				u = U(*p_rand);
				utils::warning(++fails < nb_nodes2, "Failing too much!");
			} while (get_degree(u) >= max_nb_neighbors);

			fails = 0;
			do {
				v = U(*p_rand);
				utils::warning(++fails < nb_nodes2, "Failing too much!");
			} while (get_degree(v) >= max_nb_neighbors or v == u);

			if (not get_edge(u, v))
				new_edge(u, v);

      // try adding and if there exists a cycle, remove that edge
      // TREE INSTANCES
      if (topology_type == "tree" && graph_utils::hasCycle(*this)) {
      	erase_edge(u, v);
      }
		}
	}

}


random_graph::~random_graph() { }
