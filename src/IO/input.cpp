#include "IO/input.hpp"
#include "utils.hpp"

using namespace std;
using namespace dcop_generator;
using namespace misc_utils;


int input::get_nb_instances(char *argv[]) {

    return atoi(argv[1]);
}

string input::get_file_out(char *argv[]) {

    return argv[2];
}

string input::usage() {

    string ret = "dcop-generator <nb_instances> <outfile> <instance>\n";
    ret += "\twhere:\n";
    ret += "\t  <nb_instances> = the number of instances to generate\n";
    ret += "\t  <outfile>      = the output filename (will be numbered)\n";
    ret += "\t  <instance>     =  -random | -scale-free | -grid \n";
    ret += "\n\t-random      nb_agents domain_size p1 p2"
            "\n\t\t\t"
            "[max_nb_neighbors[=nb_agents] max_constr_arity[=2]  nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]";
    ret += "\n\t-scale-free  nb_agents domain_size lambda[=1.5] p2 max_nb_neighbors"
            "\n\t\t\t"
            " [max_constr_arity[=2]  nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]";
    ret += "\n\t-grid        nb_agents domain_size p2 "
            "\n\t\t\t"
            "[max_constr_arity[=2] max_nb_neighbors[=4] "
            "nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]";
    ret += "\n\t-grid-weather        nb_agents decision_domain_size random_domain_size p2 "
            "\n\t\t\t"
            "[max_constr_arity[=2] max_nb_neighbors[=4] "
            "nb_local_variables[=1] max_nb_boundary_variables[=1] p1_local_variables[=1.0]]";
    ret += "\n\t-meeting-scheduling  nb_agents domain_size p1 p2";

    return ret;
}

void input::check_params(int argc, char *argv[]) {

    for (int i = 0; i < argc; ++i) {
        if (strcmp("-help", argv[i]) == 0) {
            cout << usage() << endl;
            exit(1);
        }
    }
    utils::massert(argc >= get_min_nb_arguments(), "Wrong number of parameters received\n" + usage());

    for (int i = 0; i < argc; ++i) {
        if (strcmp("-random", argv[i]) == 0 &&
            (argc == get_min_nb_arguments() + 4 + 3|| argc == get_min_nb_arguments() + 9 + 3))
            return;
        if (strcmp("-scale-free", argv[i]) == 0 &&
            (argc == get_min_nb_arguments() + 5 || argc == get_min_nb_arguments() + 9))
            return;
        if (strcmp("-grid", argv[i]) == 0 &&
            (argc == get_min_nb_arguments() + 3 || argc == get_min_nb_arguments() + 8))
            return;
        if (strcmp("-grid-weather", argv[i]) == 0 &&
            (argc == get_min_nb_arguments() + 3 + 2 || argc == get_min_nb_arguments() + 8 + 2))
            return;
        if (strcmp("-meeting-scheduling", argv[i]) == 0 &&
            (argc == get_min_nb_arguments() + 4 + 2))
            return;
    }

    std::cout << usage() << std::endl;
    exit(1);
}

int ::dcop_generator::input::get_min_nb_arguments() {
    return 4;
}
