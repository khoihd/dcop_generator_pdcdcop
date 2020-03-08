#ifndef DCOP_GENERATOR_KERNEL_CONSTANTS_HPP
#define DCOP_GENERATOR_KERNEL_CONSTANTS_HPP

#include <limits>       // std::numeric_limits

#include "Kernel/types.hpp"

namespace dcop_generator {

	// A singleton class for constants.
	class constants {

	public:
		static constexpr int nan = std::numeric_limits<int>::max() - 1;
		static constexpr cost_t inf = std::numeric_limits<int>::max();
		static constexpr cost_t sat = 0;
		static constexpr cost_t unsat = std::numeric_limits<int>::max();
		static constexpr oid_t nullid = std::numeric_limits<oid_t>::max();

	private:
		constants() { }
	};
}

#endif // DCOP_GENERATOR_KERNEL_CONSTANTS_HPP

