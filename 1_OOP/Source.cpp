#include <iostream>
#include <optional>

int main() {
    int value = 0; 

#ifdef DEBUG_LOG
    std::cout << "Debug mode\n";
#endif

    std::optional<int> number = 5;

    std::cout << "Number: " << *number << '\n';
    return 0;
}

