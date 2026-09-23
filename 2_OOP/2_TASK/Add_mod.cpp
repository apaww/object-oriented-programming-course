#include "Add_mod.hpp"

int add(int a, int b) {
	int c = a + b;

	if (std::rand() % 2) {
		c += std::rand();
	}

	return c;
}
