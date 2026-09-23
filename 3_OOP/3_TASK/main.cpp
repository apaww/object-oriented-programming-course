#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<int> ptr1 = std::make_unique<int>(67);
  // with unique pointer it is impossible to create its copy, so dangling pointers are irrelevant

  std::shared_ptr<int> ptr2 = std::make_shared<int>(69);
  std::shared_ptr<int> ptr3 = ptr2;
  // with shared pointer object is destroyed only after every shared pointer instance is gone

	return 0;
}
