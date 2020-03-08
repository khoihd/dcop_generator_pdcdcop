#ifndef DCOP_GENERATOR_GRAPH_SCALE_FREE_GRAPH_HPP
#define DCOP_GENERATOR_GRAPH_SCALE_FREE_GRAPH_HPP

#include <chrono>
#include <memory>
#include <random>
#include <string>

#include "Graph/graph.hpp"

namespace dcop_generator
{
	class scale_free_graph : public graph
	{
	public:
		typedef std::shared_ptr<scale_free_graph> ptr;

		// Creates a random graph.
		//
		// @param nb_nodes The number of nodes in the graph.
		// @param p1 The network connectivity
		// @param max_nb_neigbors The maximum number of neigbors for each node, if
		//   0, then it is ignored.
		scale_free_graph(int nb_nodes, double lambda = 1.5, int max_nb_neighbors = 0);

		~scale_free_graph();


	private:
		double _power_law_CDF(double a, double b, double l, double u);

		// The Network connectivity associated to this constraint graph.
		double m_p1;

		// A random engine used to generate random numbers.
		std::unique_ptr<std::default_random_engine> m_rand;
	};
}

#endif // DCOP_GENERATOR_GRAPH_SCALE_FREE_GRAPH_HPP

