#ifndef DCOP_GENERATOR_GRAPH_GRAPH_UTILS_HPP
#define DCOP_GENERATOR_GRAPH_GRAPH_UTILS_HPP

#include <vector>
#include <string>
#include <memory>


namespace dcop_generator {
    class graph;

    namespace graph_utils {

        // It returns true if the graph given as a parameter is connected.
        bool connected(const graph &pGraph);

        // It returns true if the graph given as a parameter is a tree.
        bool hasCycle(const graph &pGraph);

        // bool recurFindCycle(const graph &pGraph, int u, int v, std::vector<int> marked);

        // It returns all the cliques (as a list of nodes) of size k, of the graph
        // given as a parameter.
        std::vector<std::vector<int> > cliques(const graph &pGraph, int k);
    }
}

#endif // DCOP_GENERATOR_GRAPH_GRAPH_UTILS_HPP
