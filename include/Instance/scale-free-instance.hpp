#ifndef DCOP_GENERATOR_INSTANCE_SCALE_FREE_INSTANCE_HPP
#define DCOP_GENERATOR_INSTANCE_SCALE_FREE_INSTANCE_HPP


namespace dcop_generator
{
    class scale_free_instance : public instance
    {
    public:
        typedef std::shared_ptr<scale_free_instance> ptr;

        scale_free_instance(int nb_agents, int domain_size, double lambda, double p2, int max_nb_neighbors,
                            // optional
                            int max_constr_arity=2,
                            int nb_local_variables = 1, int max_nb_boundary_variables = 0, double p1_local_variables = 1.0);

        virtual ~scale_free_instance() { }


        virtual std::string to_string() const override;
    };
}

#endif //DCOP_GENERATOR_SCALE_FREE_INSTANCE_HPP
