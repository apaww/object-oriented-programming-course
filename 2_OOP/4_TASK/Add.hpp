#pragma once

namespace normal {
	template <typename T1>
	T1 add(const T1& a, const T1& b) {
		return a + b;
	}
}

#include <random>

namespace random {
	template <typename T1>
	T1 add(const T1& a, const T1& b) {
		T1 c = a + b;

		if (std::rand() % 2) {
			c += std::rand();
		}

		return c;
	}
}
