#ifndef DCOP_GENERATOR_GRAPH_GRAPH_HPP
#define DCOP_GENERATOR_GRAPH_GRAPH_HPP

#include <vector>
#include <string>
#include <memory>

namespace dcop_generator
{
	class graph
	{
	public:
		typedef std::shared_ptr<graph> ptr;

		// Creates a graph of a number of nodes as those given as parameter, and
		// no edges.
		graph(int nb_nodes);

		~graph();

		size_t get_nb_nodes() const;

		size_t get_nb_edges() const;

		bool get_edge(const int u, const int v) const;

		int get_node(const int i) const;

		std::vector<int> get_nodes() const;

		// It creates a new edge between nodes indexed u and v.
		// It returns true if the edge was successufully created (did not exist
		// before).
		bool new_edge(int u, int v);

		// Removes an edge between nodes indexed u and v.
		void erase_edge(int u, int v);

		// It clears all the graph edges.
		void clear();

		// It returns the node degree associated to the node given as parameter.
		int get_degree(int u) const;

		// It returns the neighbor nodes of the node given as parameter.
		std::vector<int> get_neighbors(int u) const;

		// It joins the current graph with the other given as a parameter, at the
		// node of current graph: target_node.
		// Target node is replaced by the first node of the other graph (in lex
		// oreder) and the constraints are updated accordingly.
		// TODO: needs a better comment.
		void join(const graph &other, int target_node, int max_out_nodes);

		// It returns a string description of the graph.
		std::string to_string() const;


	private:
		// The nodes of the graph
		std::vector<int> m_nodes;

		// The adjacency matrix
		std::vector<std::vector<bool> > m_edges;

		// The number of (undirected) edges of the graph.
		size_t m_nb_edges;
	};
}

#endif // DCOP_GENERATOR_GRAPH_GRAPH_HPP