// main.cpp
#include "iter.hpp"
#include <iostream>

// Fonction template pour afficher les éléments d'un tableau
template<typename T>
void print(T val) {
    std::cout << val << " ";
}

int main() {
    int intArray[] = {1, 2, 3};
    std::cout << "Testing with int :" << std::endl;
    iter(intArray, 3, print<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3};
    std::cout << "Testing with double :" << std::endl;
    iter(doubleArray, 3, print<double>);
    std::cout << std::endl;

    char charArray[] = {'a', 'b', 'c'};
    std::cout << "Testing with char :" << std::endl;
    iter(charArray, 3, print<char>);
    std::cout << std::endl;

    return 0;
}
