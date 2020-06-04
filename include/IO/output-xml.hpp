#ifndef DCOP_GENERATOR_IO_OUTPUT_XML_HPP
#define DCOP_GENERATOR_IO_OUTPUT_XML_HPP

#include <string>

#include "IO/output.hpp"
#include "Instance/instance.hpp"

namespace dcop_generator
{
  class output_xml : public output
  {
  public:
    output_xml(std::string pathout, std::string fileout, int nb_instances, int nb_start = 0);

    virtual void to_string(instance::ptr instance) override;

    virtual void to_string(instance::ptr instance, std::string file) override;

  private:

    void dump_decision_variables(std::ostream &os, std::map<variable::ptr, domain::ptr> domains);
    void dump_random_variables(std::ostream &os, std::map<variable::ptr, domain::ptr> domains);

    void dump_functions_pdc(std::ostream &os, std::vector<constraint_pdc::ptr> constraints);
    void dump_constraints_pdc(std::ostream &os, std::vector<constraint_pdc::ptr> d_constraints, std::vector<constraint_pdc::ptr> r_constraints, std::map<variable::ptr, domain::ptr> domains);

    void dump_initProb(std::ostream &os, std::map<variable::ptr, domain::ptr> domains);
    void dump_transition(std::ostream &os, std::map<variable::ptr, domain::ptr> domains);
    void dump_graph_degree(std::ostream &os, std::map<variable::ptr, int> graph);
    void dump_selfRandomCount(std::ostream &os);

    void outputRandomFunction(std::ostream &os, std::string str);
    void storeNeighbors(std::set<std::string>);
    void outputNeighborMap(std::ostream &os);

    void dump_instance(std::ostream &os);
    void dump_presentation(std::ostream &os, std::string name, int max_con_arity);
    void dump_agents(std::ostream &os, std::vector<agent::ptr> agents);
    void dump_domains(std::ostream &os, std::vector<domain::ptr> domains);
    void dump_variables(std::ostream &os, std::vector<variable::ptr> variables);
    void dump_relations(std::ostream &os, std::vector<relation::ptr> relations);
    void dump_constraints(std::ostream &os, std::vector<constraint::ptr> constraints);

    const std::string txt_d = "\"";
    const std::string open_xml_tag = "<";
    const std::string close_xml_tag = "/>\n";
  };

}

#endif // ULYSSES_INSTANCE_GENERATOR__IO__OUTPUT_XML_H_
