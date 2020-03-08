#ifndef DCOP_GENERATOR_GRAPH_RANDOM_GRAPH_HPP
#define DCOP_GENERATOR_GRAPH_RANDOM_GRAPH_HPP

#include <chrono>
#include <memory>
#include <random>
#include <string>

#include "Graph/graph.hpp"

namespace dcop_generator
{
	class random_graph : public graph
	{
	public:
		typedef std::shared_ptr<random_graph> ptr;

		// Creates a random graph.
		//
		// @param nb_nodes The number of nodes in the graph.
		// @param p1 The network connectivity
		// @param max_nb_neigbors The maximum number of neigbors for each node, if
		//   0, then it is ignored.
		random_graph(int nb_nodes, double p1, int max_nb_neighbors = 0);

		~random_graph();


	private:
		// The Network connectivity associated to this constraint graph.
		double p_p1;

		// A random engine used to generate random numbers.
		std::unique_ptr<std::default_random_engine> p_rand;
	};
}

#endif // DCOP_GENERATOR_GRAPH_RANDOM_GRAPH_HPP

