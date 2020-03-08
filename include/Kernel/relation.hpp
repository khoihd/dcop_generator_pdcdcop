#ifndef DCOP_GENERATOR_KERNEL_RELATION_HPP
#define DCOP_GENERATOR_KERNEL_RELATION_HPP

#include <string>
#include <vector>
#include <memory>
#include "Kernel/types.hpp"
#include "Kernel/constants.hpp"

namespace dcop_generator {

    class relation {

    public:
      typedef std::shared_ptr<relation> ptr;
      typedef std::pair<std::vector<int>, cost_t> relentry_t;

      relation(std::string name, int arity, cost_t def_cost = constants::inf,
               std::string semantics = "soft")
              : m_name(name), m_arity(arity), m_default_cost(def_cost),
                m_semantics(semantics)
      { }

      std::string get_name() const {
        return m_name;
      }

      std::string get_semantics() const {
        return m_semantics;
      }

      cost_t get_default_cost() const {
        return m_default_cost;
      }

      size_t get_arity() const {
        return m_arity;
      }

      std::vector<relentry_t> &get_tuples() {
        return m_tuples;
      }

      size_t get_nb_tuples() const {
        return m_tuples.size();
      }

      void add_tuple(relentry_t tuple) {
        m_tuples.push_back(tuple);
      }

      std::string to_string() const {
        std::string res = m_name + " arity: " + std::to_string(m_arity)
                          + " semantics: " + m_semantics + " def cost: "
                          + std::to_string(m_default_cost);
        for (const relentry_t &entry : m_tuples) {
          res += "\n [";
          for (int t : entry.first)
            res += std::to_string(t) + " ";
          res += "] cost: " + std::to_string(entry.second);
        }
        return res;
      }


    private:
      // The relation name
      std::string m_name;

      // The relation semantics
      std::string m_semantics;

      // The dafault cost of the relation
      cost_t m_default_cost;

      // The arity of each relation tuple.
      size_t m_arity;

      // The list of tuples with associated costs
      std::vector<relentry_t> m_tuples;
    };
}

#endif // DCOP_GENERATOR_KERNEL_RELATION_HPP
