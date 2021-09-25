#include <map>

#include "Graph/planar-graph.hpp"
#include "utils.hpp"
#include "Graph/graph-utils.hpp"

using namespace dcop_generator;
using namespace std;
using namespace misc_utils;

planar_graph::planar_graph(int nb_nodes, int max_nb_neighbors)
  : graph(nb_nodes) {

	if (max_nb_neighbors <= 0 || max_nb_neighbors >= nb_nodes)
		max_nb_neighbors = (nb_nodes - 1);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	p_rand = unique_ptr<default_random_engine>(new default_random_engine(seed));

	int max_nb_edges = (nb_nodes * (nb_nodes - 1)) / 2;

	// Generates Rows of agents:
	int nb_rows = max_nb_neighbors;
	std::map<int, std::vector<int> > map_rows;

	// Insert nodes in each row (at least 2 per row).
	// Spurious goes in the first row
	int row = 0;
	int curr_node = 0;

	while (curr_node < nb_nodes) {
		map_rows[row].push_back(curr_node++);
		row = (row + 1) % nb_rows;
	}

	int min_row_size = nb_nodes;
	// Create linear depenences among agents of the same rows
	for (auto &kv : map_rows) {
		min_row_size = min(min_row_size, (int) kv.second.size());
		for (int n = 0; n < kv.second.size() - 1; n++) {
			new_edge(kv.second[n], kv.second[n + 1]);
		}
	}

	// Pick first row and connect with all others:
	uniform_int_distribution<int> U(1, min_row_size);
	int nb_connections = U(*p_rand);
	int target = 0;
//	printf("nb connections: %d\n", nb_connections);
	for (int i = 0; i < nb_connections; i++, target++) {
		for (int r = 0; r < nb_rows - 1; r++) {
			new_edge(map_rows[r][target], map_rows[r + 1][target]);
		}
	}

//	// Print out the edges of the graph
//	std::cout << "Print out the graph" << std::endl;
//    std::cout << to_string() << std::endl;

//	std::cout << dump() << std::endl;
	utils::massert(graph_utils::connected(*this), "Graph is not connected!");
}


planar_graph::~planar_graph() { }
