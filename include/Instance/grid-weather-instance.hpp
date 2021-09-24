#ifndef DCOP_GENERATOR_INSTANCE_GRID_WEATHER_INSTANCE_HPP
#define DCOP_GENERATOR_INSTANCE_GRID_WEATHER_INSTANCE_HPP


namespace dcop_generator
{
    class grid_weather_instance : public instance
    {
    public:
        typedef std::shared_ptr<grid_weather_instance > ptr;

        grid_weather_instance (int nb_agents, int domain_size, int rand_domain_size, double p2,
                       // optional
                       int max_constr_arity=2,
                       int max_nb_neighbors=4,
                       int nb_local_variables = 1,
                       int max_nb_boundary_variables = 0,
                       double p1_local_variables = 1.0);

        virtual ~grid_weather_instance () { }


        virtual std::string to_string() const override;
    };
}

#endif //DCOP_GENERATOR_INSTANCE_GRID_WEATHER_INSTANCE_HPP
