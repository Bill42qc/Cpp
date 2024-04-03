// main.cpp
#include "Array.hpp"
#include <iostream>

int main() {
    // Create an empty Array
    Array<int> array1;
    std::cout << "array1 size: " << array1.size() << std::endl;

    // Create an Array of size 5
    Array<int> array2(5);
    std::cout << "array2 size: " << array2.size() << std::endl;

    // Access and modify elements in the Array
    for (unsigned int i = 0; i < array2.size(); ++i) {
        array2[i] = i * 10;
    }

    // Display elements of the Array
    std::cout << "array2 elements:";
    for (unsigned int i = 0; i < array2.size(); ++i) {
        std::cout << " " << array2[i];
    }
    std::cout << std::endl;

    // Test accessing an element out of range
    try {
        std::cout << "Attempting to access array2[12]: ";
        std::cout << array2[12] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
