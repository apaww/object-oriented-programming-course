#pragma once

#include <random>

template <typename T1, typename T2>
T1 add(const T1 &a, const T2 &b) {
	T1 c = a + b;

	if (std::rand() % 2) {
		c += std::rand();
	}

	return c;
}
