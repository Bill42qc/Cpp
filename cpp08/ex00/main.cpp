#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    // Creating a std::vector and initializing its elements
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    // Test easyfind with std::vector (working test)
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Value found at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test easyfind with std::vector (non-working test)
    try {
        std::vector<int>::iterator it = easyfind(vec, 6); // Value not in vector
        std::cout << "Value found at index: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Creating a std::list and initializing its elements
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    // Test easyfind with std::list (working test)
    try {
        std::list<int>::iterator it = easyfind(lst, 30);
        std::cout << "Value found at index: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test easyfind with std::list (non-working test)
    try {
        std::list<int>::iterator it = easyfind(lst, 60); // Value not in list
        std::cout << "Value found at index: " << std::distance(lst.begin(), it) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
