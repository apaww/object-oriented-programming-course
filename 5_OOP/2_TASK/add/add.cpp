#include "add.hpp"

int normal::add(const int& a, const int& b) {
	return a + b;
}

int modded::add(const int& a, const int& b) {
	int c = a + b;
	if (std::rand() % 2) {
		c += std::rand();
	}

	return c;
}

