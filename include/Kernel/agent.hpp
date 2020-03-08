#ifndef DCOP_GENERATOR_KERNEL_AGENT_HPP
#define DCOP_GENERATOR_KERNEL_AGENT_HPP

#include <string>
#include <memory>

namespace dcop_generator {

    class agent {

    public:
      typedef std::shared_ptr<agent> ptr;

      agent(std::string name)
              : m_name(name) { }

      std::string get_name() const {
        return m_name;
      }

      std::string to_string() const {
        return m_name;
      }

    private:
      // The agent name
      std::string m_name;
    };
}

#endif // ULYSSES_INSTANCE_GENERATOR__INSTANCE__AGENT_H_
