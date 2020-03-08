#include <iostream>
#include <map>
#include <string_utils.hpp>

#include "Graph/graph.hpp"
#include "utils.hpp"

using namespace dcop_generator;
using namespace std;
using namespace misc_utils;


graph::graph(int nb_nodes)
  : m_nb_edges(0) {

	for (int i = 0; i < nb_nodes; ++i)
		m_nodes.push_back(i);

	m_edges.resize(nb_nodes);
	for (int i = 0; i < nb_nodes; ++i)
		m_edges[i].resize(nb_nodes, false);
}


graph::~graph() { }


bool graph::new_edge(int u, int v) {

	utils::massert(u != v, "In general self cycles are not allowed.");

	if (m_edges[u][v])
		return false;
	m_edges[u][v] = true;
	m_edges[v][u] = true;
	++m_nb_edges;
	return true;
}


void graph::erase_edge(int u, int v) {

	if (m_edges[u][v]) {
		m_edges[u][v] = false;
		m_edges[v][u] = false;
		--m_nb_edges;
	}
}


void graph::clear() {

	for (int i = 0; i < m_edges.size(); ++i)
		std::fill(m_edges[i].begin(), m_edges[i].end(), false);
	m_nb_edges = 0;
}


int graph::get_degree(int u) const {

	int deg = 0;
	for (int i = 0; i < m_edges[u].size(); ++i)
		deg += m_edges[u][i];
	return deg;
}


vector<int> graph::get_neighbors(int u) const {

	vector<int> N;
	for (int i = 0; i < m_edges[u].size(); ++i)
		if (m_edges[u][i])
			N.push_back(i);
	return N;
}


size_t graph::get_nb_nodes() const {
	return m_nodes.size();
}

size_t graph::get_nb_edges() const {
	return m_nb_edges;
}

bool graph::get_edge(const int u, const int v) const {
	utils::massert((u < get_nb_nodes() && v < get_nb_nodes()), "Error in node encoding.");
	return m_edges[u][v];
}

int graph::get_node(const int i) const {
	utils::massert(i >= 0 and i < get_nb_nodes(), "Error in node encoding.");
	return m_nodes[i];
}

std::vector<int> graph::get_nodes() const {
	return m_nodes;
}

void graph::join(const graph &other, int target_node, int max_out_nodes) {

	vector<int> t_neighbours = get_neighbors(target_node);
	// Creates map from old nodes to new nodes.
	std::map<int, int> map_nodes;
	map_nodes[0] = target_node;
	int last_node = get_nb_nodes() - 1;

	for (int i = 1; i < other.get_nb_nodes(); ++i) {
		m_nodes.push_back(last_node + i);
		map_nodes[i] = (last_node + i);
	}

	// Expand Edges.
	m_edges.resize(get_nb_nodes());
	for (int i = 0; i < get_nb_nodes(); ++i)
		m_edges[i].resize(get_nb_nodes());

	// Clears row and column corresponding to target_node
	for (int i = 0; i <= last_node; ++i) {
		if (m_edges[i][target_node]) {
			m_edges[i][target_node] = m_edges[target_node][i] = false;
			--m_nb_edges;
		}
	}

	// Copy old edges into new graph
	for (int i = 0; i < other.get_nb_nodes(); ++i)
		for (int j = 0; j <= i; ++j)
			if (other.get_edge(i, j))
				new_edge(map_nodes[i], map_nodes[j]);

	// Merge the two graphs
	for (int i = 0; i < t_neighbours.size(); ++i) {
		int u = t_neighbours[i];
		int j = (i % max_out_nodes);//(i % other.nbNodes());
		int v = map_nodes[j];

		new_edge(u, v);
	}
}


string graph::to_string() const {

	std::string res = "Nodes: " + string_utils::get(m_nodes);
	res += "\nEdges:\n";

	// Scan only the lower triangular matrix
	for (int i = 0; i < get_nb_nodes(); ++i)
		for (int j = 0; j <= i; ++j)
			if (m_edges[i][j])
				res += std::to_string(get_node(j)) + "--" + std::to_string(get_node(i)) + "\n";

	return res;
}
