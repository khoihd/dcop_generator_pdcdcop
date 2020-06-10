#include <string>
#include <iostream>
#include <vector>
#include <Instance/meeting_scheduling_instance.hpp>
#include "Instance/random-instance.hpp"
#include "Instance/scale-free-instance.hpp"
#include "Instance/grid-instance.hpp"
#include "Instance/instance-factory.hpp"
#include "IO/input.hpp"

using namespace dcop_generator;
using namespace misc_utils;
using namespace std;

instance::ptr instance_factory::create(int argc, char* argv[]) {

    input::check_params(argc, argv);

    for (int i = 0; i < argc; ++i) {
        if (!strcmp("-random", argv[i])) {
            int nb_agents = std::stoi(argv[++i]);
            int nb_rands = std::stoi(argv[++i]);
            int dom_size = std::stoi(argv[++i]);
            int rand_dom_size = std::stoi(argv[++i]);
            double p1_agents = std::stof(argv[++i]);
            double p2 = 1 - std::stof(argv[++i]);

            if (argc > input::get_min_nb_arguments() + 4 + 2) {
                int max_nb_neigbors = std::stoi(argv[++i]);
                int max_constr_arity = std::stoi(argv[++i]);
                int nb_local_vars = std::stoi(argv[++i]);
                int max_nb_boundary_vars = std::stoi(argv[++i]);
                double p1_local_vars = std::stoi(argv[++i]);

                return make_shared<random_instance>(nb_agents,
                                                    nb_rands,
                                                    dom_size,
                                                    rand_dom_size,
                                                    p1_agents,
                                                    p2,
                                                    max_nb_neigbors,
                                                    max_constr_arity,
                                                    nb_local_vars,
                                                    max_nb_boundary_vars,
                                                    p1_local_vars);
            }
            else {
                return make_shared<random_instance>(nb_agents, nb_rands, dom_size, rand_dom_size, p1_agents, p2);
            }
        }

        if (!strcmp("-scale-free", argv[i])) {
            int nb_agents = std::stoi(argv[++i]);
            int dom_size = std::stoi(argv[++i]);
            double lambda = std::stof(argv[++i]);
            double p2 = 1 - std::stof(argv[++i]);
            int max_nb_neigbors = std::stoi(argv[++i]);

            if (argc > input::get_min_nb_arguments() + 5) {
                int max_constr_arity = std::stoi(argv[++i]);
                int nb_local_vars = std::stoi(argv[++i]);
                int max_nb_boundary_vars = std::stoi(argv[++i]);
                double p1_local_vars = std::stoi(argv[++i]);

                return make_shared<scale_free_instance>(nb_agents,
                                                        dom_size,
                                                        lambda,
                                                        p2,
                                                        max_nb_neigbors,
                                                        max_constr_arity,
                                                        nb_local_vars,
                                                        max_nb_boundary_vars,
                                                        p1_local_vars);
            }
            else {
                return make_shared<scale_free_instance>(nb_agents, dom_size, lambda, p2, max_nb_neigbors);
            }
        }

        if (!strcmp("-grid", argv[i])) {
            int nb_agents = std::stoi(argv[++i]);
            int dom_size = std::stoi(argv[++i]);
            double p2 = 1 - std::stof(argv[++i]);

            if (argc > input::get_min_nb_arguments() + 3) {
                int max_constr_arity = std::stoi(argv[++i]);
                int max_nb_neigbors = std::stoi(argv[++i]);

                int nb_local_vars = std::stoi(argv[++i]);
                int max_nb_boundary_vars = std::stoi(argv[++i]);
                double p1_local_vars = std::stoi(argv[++i]);

                return make_shared<grid_instance>(nb_agents,
                                                  dom_size,
                                                  p2,
                                                  max_constr_arity,
                                                  max_nb_neigbors,
                                                  nb_local_vars,
                                                  max_nb_boundary_vars,
                                                  p1_local_vars);
            }
            else {
                return make_shared<grid_instance>(nb_agents, dom_size, p2);
            }
        }

        if (!strcmp("-meeting-scheduling", argv[i])) {
            int nb_agents = std::stoi(argv[++i]);
            int nb_rands = std::stoi(argv[++i]);
            int dom_size = std::stoi(argv[++i]);
            int rand_dom_size = std::stoi(argv[++i]);
            double p1_agents = std::stof(argv[++i]);
            double p2 = 1 - std::stof(argv[++i]);

            // return make_shared<meeting_scheduling_instance>(nb_agents, dom_size, p1_agents, p2);
            return make_shared<meeting_scheduling_instance>(nb_agents, nb_rands, dom_size, rand_dom_size, p1_agents, p2);
        }

    }
    return nullptr;
}
