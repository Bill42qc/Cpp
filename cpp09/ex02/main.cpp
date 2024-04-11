#include <iostream>
#include <fstream>
#include <vector>
#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << argv[1] << "\n";
        return 1;
    }

    std::vector<int> vecSequence;
    int num;
    while (inputFile >> num) {
        if (num <= 0) {
            std::cerr << "Error: Invalid input '" << num << "'\n";
            return 1;
        }
        vecSequence.push_back(num);
    }

    inputFile.close();

    std::cout << "Before:";
    for (size_t i = 0; i < vecSequence.size(); ++i) {
        std::cout << " " << vecSequence[i];
    }
    std::cout << std::endl;

    mergeInsertSort(vecSequence);

    std::cout << "After:";
    for (size_t i = 0; i < vecSequence.size(); ++i) {
        std::cout << " " << vecSequence[i];
    }
    std::cout << std::endl;

    return 0;
}
