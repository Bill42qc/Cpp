#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange("data.csv");
    bitcoinExchange.processInputFile(argv[1]);

    return 0;
}
