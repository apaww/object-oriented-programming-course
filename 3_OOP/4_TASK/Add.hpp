#pragma once

namespace normal {
	template <typename T, typename T1>
	T add(const T1& a, const T1& b) {
		return a + b;
	}
}

#include <random>

namespace modded {
	template <typename T, typename T1>
	T add(const T1& a, const T1& b) {
		T c = a + b;

		if (std::rand() % 2) {
			c += std::rand();
		}

		return c;
	}
}
