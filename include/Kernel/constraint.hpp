#ifndef DCOP_GENERATOR_KERNEL_CONSTRAINT_HPP
#define DCOP_GENERATOR_KERNEL_CONSTRAINT_HPP

#include <string>
#include <vector>
#include <memory>

namespace dcop_generator {

    class constraint {

    public:
      typedef std::shared_ptr<constraint> ptr;

      constraint(std::string name, std::vector<int> scope_id,
                 std::vector<std::string> scope,
                 std::string rel)
              : m_name(name), m_scope_id(scope_id), m_scope(scope), m_relation(rel)
      { }

      std::string get_name() const {
        return m_name;
      }

      std::vector<std::string> &get_scope() {
        return m_scope;
      }

      std::vector<int> &get_scope_id() {
        return m_scope_id;
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
      // The constraint name
      std::string m_name;

      // The name of the variables in the scope of this constraint.
      std::vector<std::string> m_scope;

      // The ID of the variables in the scope of this constraint.
      std::vector<int> m_scope_id;

      // The name of the relation associated to this constraint.
      std::string m_relation;
    };
}

#endif // DCOP_GENERATOR_KERNEL_CONSTRAINT_HPP
