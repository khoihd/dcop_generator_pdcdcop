#ifndef DCOP_GENERATOR_KERNEL_constraint_pdc_HPP
#define DCOP_GENERATOR_KERNEL_constraint_pdc_HPP

#include <string>
#include <vector>
#include <memory>

namespace dcop_generator {

    class constraint_pdc {

    public:
      typedef std::shared_ptr<constraint_pdc> ptr;

      constraint_pdc(std::string name,
                 std::vector<std::string> scope,
                 std::string rel)
              : m_name(name), m_scope(scope), m_relation(rel)
      { }

      std::string get_name() const {
        return m_name;
      }

      std::vector<std::string> &get_scope() {
        return m_scope;
      }

      size_t get_arity() const {
        return m_scope.size();
      }

      std::string get_relation() const {
        return m_relation;
      }

      std::string to_string() const {
        std::string res = m_name + " rel: " + m_relation + " (";
        for (std::string s : m_scope)
          res += s + " ";
        res += ")";
        return res;
      }


    private:
      // The constraint_pdc name
      std::string m_name;

      // The name of the variables in the scope of this constraint_pdc.
      std::vector<std::string> m_scope;

      // The ID of the variables in the scope of this constraint_pdc.
      // std::vector<int> m_scope_id;

      // The name of the relation associated to this constraint_pdc.
      std::string m_relation;
    };
}

#endif // DCOP_GENERATOR_KERNEL_constraint_pdc_HPP
