#include "RPN.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "./RPN <expression>" << std::endl;
        return 1;
    }

    try {
        int result = evaluateRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (const char* error) {
        std::cerr << "Error " << error << std::endl;
        return 1;
    }

    return 0;
}
