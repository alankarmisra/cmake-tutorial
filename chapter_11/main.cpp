#include <iostream>

int main() {
#ifdef DEBUG_MODE
    std::cout << "Hello World from Debug mode!" << std::endl;
#else
    std::cout << "Hello World from Release mode!" << std::endl;
#endif
    return 0;
}