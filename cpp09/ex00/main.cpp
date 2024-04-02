#include "BitcoinExchange.hpp"
#include <ostream>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    std::string inputFileName(argv[1]);
    BitcoinExchange exchange("data.csv");
    exchange.processFile(inputFileName);

    return 0;
}
