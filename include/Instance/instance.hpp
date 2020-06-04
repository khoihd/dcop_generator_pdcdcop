#ifndef DCOP_GENERATOR_INSTANCE_INSTANCE_HPP
#define DCOP_GENERATOR_INSTANCE_INSTANCE_HPP

#include <cassert>
#include <string>
#include <vector>
#include <map>

#include "Kernel/agent.hpp"
#include "Kernel/constraint.hpp"
#include "Kernel/constraint_pdc.hpp"
#include "Kernel/domain.hpp"
#include "Kernel/relation.hpp"
#include "Kernel/variable.hpp"
#include "Graph/graph.hpp"


namespace dcop_generator
{
    class instance
    {
    public:
        typedef std::shared_ptr<instance> ptr;

        instance();

        ~instance();

        void save(agent::ptr agent) {
            m_agents.push_back(agent);
            m_agent_with_name[agent->get_name()] = m_agents.size() - 1;
        }

        agent& get_agent(std::string name) {
            assert(m_agent_with_name.find(name) != m_agent_with_name.end());
            return *m_agents[m_agent_with_name[name]];
        }

        void save_graph_degree(variable::ptr var, int degree) {
          graphDegree[var] = degree;
        }

        std::map<variable::ptr, int> & get_graph_degree() {
          return graphDegree;
        }

        void save_decision_domain(variable::ptr var, domain::ptr dom) {
          m_decision_domains[var] = dom;
        }

        void save_random_domain(variable::ptr var, domain::ptr dom) {
          m_random_domains[var] = dom;
        }

        std::map<variable::ptr, domain::ptr> & get_decision_domains() {
            return m_decision_domains;
        }

        std::map<variable::ptr, domain::ptr> & get_random_domains() {
            return m_random_domains;
        }

        void save_decision_variable(variable::ptr var) {
          m_decision_variables.push_back(var);
        }

        void save_random_variable(variable::ptr rand_var) {
          m_random_variables.push_back(rand_var);
        }

        std::vector<variable::ptr> & get_decision_variables() {
            return m_decision_variables;
        }

        std::vector<variable::ptr> & get_random_variables() {
            return m_random_variables;
        }

        void save(constraint_pdc::ptr con) {
            m_constraints_pdc.push_back(con);
        }

        std::vector<constraint_pdc::ptr>& get_constraints_pdc() {
            return m_constraints_pdc;
        }




        std::vector<agent::ptr> & get_agents() {
            return m_agents;
        }

        void save(domain::ptr dom) {
            m_domains.push_back(dom);
            m_domain_with_name[dom->get_name()] = m_domains.size() - 1;
        }

        domain& get_domain(std::string name) {
            assert(m_domain_with_name.find(name) != m_domain_with_name.end());
            return *m_domains[m_domain_with_name[name]];
        }

        std::vector<domain::ptr> & get_domains() {
            return m_domains;
        }

        void save(variable::ptr var) {
            m_variables.push_back(var);
            m_variable_with_name[var->get_name()] = m_variables.size() - 1;
        }

        variable& get_variable(std::string name) {
            assert(m_variable_with_name.find(name) != m_variable_with_name.end());
            return *m_variables[m_variable_with_name[name]];
        }

        std::vector<variable::ptr> & get_variables() {
            return m_variables;
        }

        void save(constraint::ptr con) {
            m_constraints.push_back(con);
            m_constraint_with_name[con->get_name()] = m_constraints.size() - 1;
        }

        constraint& get_constraint(std::string name) {
            assert(m_constraint_with_name.find(name) != m_constraint_with_name.end());
            return *m_constraints[m_constraint_with_name[name]];
        }

        std::vector<constraint::ptr>& get_constraints() {
            return m_constraints;
        }

        void save(relation::ptr rel) {
            m_relations.push_back(rel);
            m_relation_with_name[rel->get_name()] = m_relations.size() - 1;
        }

        relation& get_relation(std::string name) {
            assert(m_relation_with_name.find(name) != m_relation_with_name.end());
            return *m_relations[m_relation_with_name[name]];
        }

        std::vector<relation::ptr> & get_relations() {
            return m_relations;
        }

        int get_max_constraint_arity() const {
            return m_max_constraint_arity;
        }

        std::string get_type() const {
            return type;
        }

        virtual std::string to_string() const;


        double getP1() const {
            return p1;
        }

        void setP1(double p1) {
            instance::p1 = p1;
        }

        double getP2() const {
            return p2;
        }

        void setP2(double p2) {
            instance::p2 = p2;
        }

    protected:
        virtual void add_decision_variables(std::vector<int> variable_ids, int d_min, int d_max, graph input_graph);
        virtual void add_random_variables(int random_variable_count, int d_min, int d_max);
        virtual void add_constraint_pdcdcop(std::vector<variable::ptr> variables, int arity, std::string rel_name = "");

        // Given the set of agent id, creates the instance agents.
        virtual void add_agents(std::vector<int> agents_id);

        // Creates the instance variables, given the set of problem nodes,
        // and the specifics for their domain. The variables are mapped to the
        // corresponding agent with the p_map_vars_to_agents mapping.
        virtual void add_variables(std::vector<int> variables_id, int d_min, int d_max);
        // Creates a new relation of arity, constraint tighness and value range
        // given as parameter. The values and constraint costs are randomly
        // generated via uniform distribution ranging respectively in [d_min, d_max]
        // and [0,1000];
        virtual void add_relation(int arity, double p2, int d_min, int d_max, std::string rel_name = "");

        // Creates a new constraint whose scope is given as a paramter and
        // associates it to the relation with corresponding arity.
        virtual void add_constraint(std::vector<int> variables, int arity, std::string rel_name = "");

        std::vector<variable::ptr> m_decision_variables;
        std::vector<variable::ptr> m_random_variables;
        std::map<variable::ptr, domain::ptr> m_decision_domains;
        std::map<variable::ptr, domain::ptr> m_random_domains;
        std::vector<constraint_pdc::ptr> m_constraints_pdc;
        std::map<variable::ptr, int> graphDegree;

        std::vector<agent::ptr> m_agents;
        std::map<std::string, int> m_agent_with_name;
        std::vector<variable::ptr> m_variables;
        std::map<std::string, int> m_variable_with_name;
        std::vector<domain::ptr> m_domains;
        std::map<std::string, int> m_domain_with_name;
        std::vector<constraint::ptr> m_constraints;
        std::map<std::string, int> m_constraint_with_name;
        std::vector<relation::ptr> m_relations;
        std::map<std::string, int> m_relation_with_name;
        int m_max_constraint_arity;
        double p1;
        double p2;
        std::string type;
        // Maps variables graph nodes to agent's ID.
        std::map<int, int> m_vars_to_agents;
    };
}

#endif // DCOP_GENERATOR_INSTANCE_INSTANCE_HPP
