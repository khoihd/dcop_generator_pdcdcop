#ifndef DCOP_GENERATOR_GRAPH_PLANAR_GRAPH_HPP
#define DCOP_GENERATOR_GRAPH_PLANAR_GRAPH_HPP

#include <chrono>
#include <memory>
#include <random>
#include <string>

#include "Graph/graph.hpp"

namespace dcop_generator
{
  class planar_graph : public graph
  {
   public:
    typedef std::shared_ptr<planar_graph> ptr;
     
    // Creates a random graph.
    //
    // @param nb_nodes The number of nodes in the graph.
    // @param max_nb_neigbors The maximum number of neigbors for each node, if
    //   0, then it is ignored.
    planar_graph(int nb_nodes, int max_nb_neighbors=0);

    ~planar_graph();


  private:
    // A random engine used to generate random numbers.
    std::unique_ptr<std::default_random_engine> p_rand;
  };

}
#endif // DCOP_GENERATOR_GRAPH_PLANNAR_GRAPH_HPP