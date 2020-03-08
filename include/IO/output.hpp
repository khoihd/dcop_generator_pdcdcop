#ifndef DCOP_GENERATOR_IO_OUTPUT_HPP
#define DCOP_GENERATOR_IO_OUTPUT_HPP

#include <string>

#include "Instance/instance.hpp"
#include "utils.hpp"
#include "Kernel/constants.hpp"

namespace dcop_generator
{
	class output
	{
	public:
		typedef std::shared_ptr<output> ptr;

		output(std::string pathout, std::string fileout, int nb_instances, int nb_start = 0);

		virtual void to_string(instance::ptr instance);

		virtual void to_string(instance::ptr instance, std::string file) = 0;

	protected:
		virtual std::string cost_to_string(int cost);

		int get_curr_instance() const {
			return m_curr_insance;
		}
	private:
		std::string m_pathout;

		std::string m_fileout;

		int m_nb_instances;

		int m_curr_insance;
	};
}

#endif // DCOP_GENERATOR_IO_OUTPUT_HPP
