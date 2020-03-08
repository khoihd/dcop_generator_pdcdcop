#include <Graph/graph-utils.hpp>
#include "Graph/scale-free-graph.hpp"
#include "utils.hpp"

using namespace dcop_generator;
using namespace std;
using namespace misc_utils;
  
scale_free_graph::scale_free_graph(int nb_nodes, double lambda, int max_nb_neighbors)
  : graph(nb_nodes) {

	if (max_nb_neighbors == 0)
		max_nb_neighbors = nb_nodes;

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	m_rand = unique_ptr<default_random_engine>(new default_random_engine(seed));

	// Generates random edges
	uniform_int_distribution<int> U(0, nb_nodes - 1);
	std::uniform_real_distribution<double> uniform_CDF(0, 1);

	//const graph &const_this = *this;
	do {
		graph::clear();
		for (int u = 0; u < nb_nodes; u++) {

			if(graph::get_degree(u) >= max_nb_neighbors)
				continue;
			// Select node degree distriubtion:
			int ne = _power_law_CDF(0.0, max_nb_neighbors, lambda, uniform_CDF(*m_rand));

			// Select at random 'ne' nodes to connect with this node.
			for (int i = 0; i < ne; i++) {
				// check current node max degree
				if(graph::get_degree(u) >= max_nb_neighbors)
					break;

				int v = u, n_trials = 0;
				do {
					v = U(*m_rand);
					if(graph::get_degree(v) >= (max_nb_neighbors-1))
						continue;
				} while (v == u && ++n_trials <= 1000);

				if(n_trials >= 1000)
					break;

				if (not get_edge(u, v))
					new_edge(u, v);
			}
		}
	} while (!graph_utils::connected(*this));

}


scale_free_graph::~scale_free_graph()
{ }


// [a,b] = range of distribution
// l     = distribution power
// u     = uniform variate (value generated via a uniform distr. [0,1]
double scale_free_graph::_power_law_CDF( double a, double b, double l, double u )
{
  double _e = 1/(double)(l+1);
  double _b = ( pow(b, l+1) - pow(a, l+1) )*u + pow(a, l+1);
  return pow( _b, _e );
}
