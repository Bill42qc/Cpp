#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) : databaseFile(databaseFile) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : databaseFile(other.databaseFile) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        databaseFile = other.databaseFile;
    }
    return *this;
}

void BitcoinExchange::processFile(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::map<std::string, float> bitcoinValues;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        char separator;

        if (!(iss >> dateStr >> separator >> valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (separator != '|' || dateStr.size() != 10 || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value = strtof(valueStr.c_str(), NULL);
        if (value <= 0 && value != -1) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        bitcoinValues[dateStr] = value;
    }
    file.close();

    std::ifstream db(databaseFile.c_str());
    if (!db) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string lastDate;
    while (std::getline(db, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        char separator;

        if (!(iss >> dateStr >> separator >> valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (separator != ',' || dateStr.size() != 10 || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value = strtof(valueStr.c_str(), NULL);
        if (value <= 0 && value != -1) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        bitcoinValues[dateStr] = value;
        lastDate = dateStr;
    }
    db.close();

    file.open(inputFile.c_str());
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string dateStr, valueStr;
        char separator;

        if (!(iss >> dateStr >> separator >> valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (separator != '|' || dateStr.size() != 10 || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value = strtof(valueStr.c_str(), NULL);
        if (value <= 0 && value != -1) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (bitcoinValues.find(dateStr) != bitcoinValues.end()) {
            std::cout << dateStr << " => " << value << " = " << bitcoinValues[dateStr] << std::endl;
        } else {
            std::cout << dateStr << " => " << value << " = " << bitcoinValues[lastDate] << std::endl;
        }
    }
    file.close();
}
