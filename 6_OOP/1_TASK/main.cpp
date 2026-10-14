#include <iostream>
#include "Rectangle.hpp"

int main() {
	Rectangle original(3., 5.);
	Rectangle copied = original;

	Rectangle assignment;
	assignment = original;

	return 0;
}
