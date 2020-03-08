#ifndef DCOP_GENERATOR_INSTANCE_RANDOM_INSTANCE_HPP
#define DCOP_GENERATOR_INSTANCE_RANDOM_INSTANCE_HPP

#include <map>
#include <string>
#include <vector>

#include "Instance/instance.hpp"

namespace dcop_generator
{
    class random_instance : public instance
    {
    public:
        typedef std::shared_ptr<random_instance> ptr;

        // It generates a number of random instances which are described by the
        // paramter specified as input.
        //
        // @param nb_agents The number of agents of the problem.
        // @param nb_local_variables The number of local variables of each agent.
        // @param domain_size The number of elements in range [1...dom_size]
        //        associated to each variable of the problem.
        // @param max_constr_arity The higher constraint arity among all
        //        constraints of the problem.
        // @param max_nb_neighbors The maximum number of an agent's neighbor.
        // @param max_nb_boundary_variables The maximum number of an agent's
        //        boundary variables.
        // @param p1_local_variables The graph connectivity among the local
        // variables of an agent.
        // @param p1_agents The graph connectivity among agents.
        // @param p2 The constraint tightness
        random_instance(int nb_agents, int nb_rands, int domain_size, int random_domain_size, double p1_agents, double p2,
                        // optional
                        int max_nb_neighbors = 0,
                        int max_constr_arity = 2,
                        int nb_local_variables = 1,
                        int max_nb_boundary_variables = 1,
                        double p1_local_variables = 1.0);

        ~random_instance();

    protected:
        virtual std::string to_string() const override;
    };
}


#endif // DCOP_GENERATOR_INSTANCE_RANDOM_INSTANCE_HPP
