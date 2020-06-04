#include "IO/output.hpp"

using namespace dcop_generator;

output::output(std::string pathout, std::string fileout, int nb_instances, int nb_start)
        : m_pathout(pathout), m_fileout(fileout), m_nb_instances(nb_instances),
          m_curr_insance(nb_start) {

    // Create folder if necessary:
    // misc_utils::utils::create_dir(pathout);
}

void output::to_string(instance::ptr instance) {
    // std::string file = m_pathout + "/rep_" + std::to_string(m_curr_insance) + "_" + m_fileout;
    std::string file = m_pathout + "/" + std::to_string(m_curr_insance);
    // Template pattern
    to_string(instance, file);

    m_curr_insance++;
}

std::string output::cost_to_string(int cost) {

    if (cost == constants::inf)
        return "infinity";
    if (cost == -constants::inf)
        return "-infinity";
    return std::to_string(cost);
}
