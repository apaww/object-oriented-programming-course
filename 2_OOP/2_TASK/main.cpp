#include <iostream>
#include "Add.hpp"
#include "Add_mod.hpp"

int main() {
	int a, b;

	std::cin >> a >> b;
	std::cout << add(a, b) << std::endl;

	return 0;
}
