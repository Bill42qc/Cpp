#pragma once

#include <string>
#include <map>
#include <fstream>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    BitcoinExchange(const std::string& filename);
    double getBitcoinPrice(const std::string& date) const;

    bool isValidValue(const std::string& value_str) const;

    void processInputFile(const std::string& input_filename);

private:
    std::map<std::string, double> bitcoinPrices;
};
