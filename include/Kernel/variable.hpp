#ifndef DCOP_GENERATOR_KERNEL_VARIABLE_HPP
#define DCOP_GENERATOR_KERNEL_VARIABLE_HPP

#include <string>
#include <memory>

namespace dcop_generator {

    class variable {

    public:
        typedef std::shared_ptr<variable> ptr;

        variable(int id, std::string name, std::string domain, std::string agent)
                : m_id(id), m_name(name), m_domain(domain), m_agent(agent) { }

        int get_id() const {
            return m_id;
        }

        std::string get_name() const {
            return m_name;
        }

        std::string get_domain() const {
            return m_domain;
        }

        std::string get_agent() const {
            return m_agent;
        }

        std::string to_string() const {
            return m_name + " (domain: " + m_domain + ") owned by: " + m_agent;
        }

    private:
        // The variable id
        int m_id;
        // The Variable name.
        std::string m_name;
        // The domain name associated to this variable.
        std::string m_domain;
        // The name of the agent which ownes this variable,
        std::string m_agent;
    };
}

#endif // DCOP_GENERATOR_KERNEL_VARIABLE_HPP
