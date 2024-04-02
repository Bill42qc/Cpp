#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    MutantStack<int> mutantStack;
    std::list<int> stdList;

    // MutantStack tests
    mutantStack.push(5);
    mutantStack.push(17);
    std::cout << "Top element in MutantStack: " << mutantStack.top() << std::endl;
    mutantStack.pop();
    std::cout << "Size of MutantStack after popping: " << mutantStack.size() << std::endl;
    mutantStack.push(3);
    mutantStack.push(5);
    mutantStack.push(737);
    mutantStack.push(0);
    
    // Print elements in MutantStack
    std::cout << "Elements in MutantStack: ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // List tests
    stdList.push_back(5);
    stdList.push_back(17);
    std::cout << "Top element in std::list: " << stdList.back() << std::endl;
    stdList.pop_back();
    std::cout << "Size of std::list after popping: " << stdList.size() << std::endl;
    stdList.push_back(3);
    stdList.push_back(5);
    stdList.push_back(737);
    stdList.push_back(0);

    // Print elements in std::list
    std::cout << "Elements in std::list: ";
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
