#include "BitcoinExchange.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    bitcoinPrices = other.bitcoinPrices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        bitcoinPrices = other.bitcoinPrices;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::invalid_argument("Error: could not open bitcoin prices file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date_str, price_str;
        if (std::getline(ss, date_str, ',') && std::getline(ss, price_str)) {
            try {
                double price = std::stod(price_str);
                bitcoinPrices[date_str] = price;
            } catch (const std::invalid_argument& e) {
                // Skip invalid lines
                continue;
            } catch (const std::out_of_range& e) {
                // Skip lines with too large values
                continue;
            }
        }
    }

    file.close();
}

double BitcoinExchange::getBitcoinPrice(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = bitcoinPrices.lower_bound(date);
    if (it == bitcoinPrices.begin() || (it != bitcoinPrices.end() && it->first != date)) {
        --it;
    }
    return it->second;
}

bool BitcoinExchange::isValidValue(const std::string& value_str) const {
    try {
        double value = std::stod(value_str);
        if (value <= 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            return false;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: not a valid value => " << value_str << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::processInputFile(const std::string& input_filename) {
    std::ifstream input_file(input_filename);
    if (!input_file) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input_file, line)) {
        if (line.find('|') == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::stringstream ss(line);
        std::string date_str, value_str;
        getline(ss, date_str, '|');
        getline(ss, value_str, '|');

        if (!isValidValue(value_str)) {
            continue;
        }

        try {
            double value = std::stod(value_str);
            std::cout << date_str << " => " << value_str << " = " << getBitcoinPrice(date_str) * value << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: not a valid value => " << value_str << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: too large a number." << std::endl;
        }
    }

    input_file.close();
}
