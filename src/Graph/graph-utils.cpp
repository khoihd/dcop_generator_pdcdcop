#include <queue>
#include <utils.hpp>

#include "Graph/graph.hpp"
#include "Graph/graph-utils.hpp"

using namespace dcop_generator;
using namespace std;
using namespace misc_utils;

const int VISITED = 0;
const int UNVISITED = -1;

void printVector(std::vector<int> vt) {
	for (int node : vt) {
		std::cout << node << " ";
	}
	std::cout << endl;
	std::cout << "===========";
	std::cout << endl;
}

bool recurFindCycle(const graph& pGraph, int v, int u, vector<int> marked) {
	// printVector(marked);
  marked[v] = VISITED;
	// std::cout << "v " << v << " is marked as true" << endl;
	// std::cout << "v = " << v << ", u = " << u << endl;
	for (int w : pGraph.get_neighbors(v)) {
		// std::cout << "Neighbor " << w << endl;
		// printVector(marked);
		if (marked[w] == UNVISITED) {
			marked[w] = VISITED;
			// std::cout << "w " << w << " is marked as true" << endl;
			// printVector(marked);
      if (recurFindCycle(pGraph, w, v, marked)) {
				return true;
			}
    } else if (w != u) {
				// std::cout << "w = " << v << " != u = " << u << endl;
				return true;
    }
  }
	return false;
}

bool graph_utils::hasCycle(const graph& pGraph) {
	int root = pGraph.get_node(0);
	vector<int> marked(pGraph.get_nb_nodes(), UNVISITED);
	// printVector(marked);
	return recurFindCycle(pGraph, root, root, marked);
}

bool graph_utils::connected(const graph& pGraph) {

	if (pGraph.get_nb_edges() < (pGraph.get_nb_nodes() - 1))
		return false;

	enum node_state {
		kUnvisited = 0, kTraversed, kOpened, kClosed
	};

	vector<node_state> status(pGraph.get_nb_nodes(), kUnvisited);
	queue<int> traversal_queue;
	int n_components = 0;

	for (int n : pGraph.get_nodes()) {
		if (status[n] == kTraversed) continue;

		traversal_queue.push(n);

		while (!traversal_queue.empty()) {
			int t = traversal_queue.front();
			traversal_queue.pop();

			for (int u : pGraph.get_neighbors(t)) {
				if (status[u] == kUnvisited) {
					status[u] = kOpened;
					traversal_queue.push(u);
				}
			}
			status[t] = kTraversed;
		}
		++n_components;
	}
	return (n_components == 1);
}


vector< vector<int> > graph_utils::cliques(const graph &pGraph, int size) {
	vector<int> nodes = pGraph.get_nodes();
	vector<int> clique(size);
	vector<vector<int> > cliques;
	do {
		bool is_clique = true;
		for (int u = 0; u < size; ++u) {
			for (int v = u + 1; v < size; ++v) {
				if (!pGraph.get_edge(nodes[u], nodes[v])) {
					is_clique = false;
					break;
				}
			}
			if (!is_clique) break;
		}

		if (is_clique) {
			clique.assign(nodes.begin(), nodes.begin() + size);
			cliques.push_back(clique);
		}

	} while (utils::next_combination
			(nodes.begin(), nodes.begin() + size, nodes.end()));

    printf("Print out clique...\n");
	for (auto clique : cliques) {
	    printf("Clique = \n");
	    for (auto node : clique) {
	        std:cout << std::to_string(node) + " " << std::endl;
	    }
	}

	return cliques;
}
