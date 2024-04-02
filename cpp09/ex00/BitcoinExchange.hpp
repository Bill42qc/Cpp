#pragma once

#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void processFile(const std::string& inputFile);

private:
    std::string databaseFile;
};
