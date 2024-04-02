#pragma once

#include <string>

class Converter {
public:
    Converter(const std::string& rawInput); 
    Converter(const Converter& other);
    Converter& operator=(const Converter& other);
    ~Converter();

    void convertAndPrint();

private:
    std::string _rawInput;

    char toChar();
    int toInt();
    float toFloat();
    double toDouble();
};
