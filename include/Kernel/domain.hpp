#ifndef DCOP_GENERATOR_KERNEL_DOMAIN_HPP
#define DCOP_GENERATOR_KERNEL_DOMAIN_HPP

#include <string>
#include <memory>
#include <numeric>      // std::iota

namespace dcop_generator {

    class domain {

    public:
      typedef std::shared_ptr<domain> ptr;

      domain(std::string name, int min, int max)
              : m_name(name), m_min(min), m_max(max)
      { }

      std::string get_name() const {
        return m_name;
      }

      int get_min() const {
        return m_min;
      }

      int get_max() const {
        return m_max;
      }

      std::vector<int> get_values() {
        std::vector<int> v(domain::get_size());
        std::iota(std::begin(v), std::end(v), domain::get_min());
        return v;
      }

      size_t get_size() const {
        return (m_max - m_min + 1);
      }

      std::string to_string() const {
        // return m_name + " [" + std::to_string(m_min) + ", " +
        //         std::to_string(m_max) + "]";
        return "[" + std::to_string(m_min) + "," +
                std::to_string(m_max) + "]";
      }

    private:
      // The domain name
      std::string m_name;

      // (Bound) domain minimum value
      int m_min;

      // (Bound) domain maximum value
      int m_max;
    };
}

#endif // DCOP_GENERATOR_KERNEL_DOMAIN_HPP
