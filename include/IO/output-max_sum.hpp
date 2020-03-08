#ifndef DCOP_GENERATOR_IO_OUTPUT_MAXSUM_HPP
#define DCOP_GENERATOR_IO_OUTPUT_MAXSUM_HPP

#include <string>

#include "IO/output.hpp"
#include "Instance/instance.hpp"

namespace dcop_generator
{
  class output_maxsum: public output
  {
  public:
      output_maxsum (std::string pathout, std::string fileout, int nb_instances, int nb_start = 0);

      virtual void to_string(instance::ptr instance) override;

      virtual void to_string(instance::ptr instance, std::string file) override;

  private:
    int domain_size = 0;
      void dump_instance(std::ostream &os);
      void dump_agents(std::ostream &os, std::vector<agent::ptr> agents,
                       std::vector<domain::ptr> domains);
      void dump_constraints (std::ostream &os, std::vector<constraint::ptr> constraints,
                             std::vector<relation::ptr> relations );
    const std::string txt_d = "\"";
    const std::string space_ms = " ";
  };

}

#endif // DCOP_GENERATOR_IO_OUTPUT_MAXSUM_HPP
