#ifndef DCOP_GENERATOR_IO_OUTPUT_TOPOLOGY_HPP
#define DCOP_GENERATOR_IO_OUTPUT_TOPOLOGY_HPP

#include <string>

#include "IO/output.hpp"
#include "Instance/instance.hpp"

namespace dcop_generator
{
  class output_topology : public output
  {
  public:
      output_topology(std::string pathout, std::string fileout, int nb_instances, int nb_start = 0);

      virtual void to_string(instance::ptr instance) override;

      virtual void to_string(instance::ptr instance, std::string file) override;

  private:
      int domain_size = 0;

      void dump_topology(std::ostream &os, instance::ptr pInstance);

      const std::string m_txt_d = "\"";
      const std::string m_space_topo = "->";
  };

}

#endif // DCOP_GENERATOR_IO_OUTPUT_TOPOLOGY_HPP
