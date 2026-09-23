#include <iostream>
#include <utility>

int main() {
  int *ptr1 {new int{67}};
  int *ptr2 {new int[7] {1, 2, 3, 4, 5, 6}};

  for (int idx = 0; idx < 6; ++idx) {
    std::cout << *(ptr2 + idx) << (idx < 5 ? ", " : "\n");
  }

  int *dangling = ptr1;
  delete ptr1;
  // dangling now points to the memory that was freed already
  // if we try to change value by this pointer, it may cause underfined behavior
  *dangling = 1;  // unacceptable practice
  dangling = nullptr; // good practice

  int num = 10;
  int ind = 3;
  int temp = 0;
  for (int idx = 0; idx < 7; ++idx) {
    if (idx == ind) {
      temp = *(ptr2 + idx);
      *(ptr2 + idx) = num;
    } else if (idx > ind) {
      std::swap(temp, *(ptr2 + idx));
    }
  }

  for (int idx = 0; idx < 7; ++idx) {
    std::cout << *(ptr2 + idx) << (idx < 6 ? ", " : "\n");
  }

  delete[] ptr2;

	return 0;
}
