#include <iostream>
#include "Converter.hpp"

//Cons
Converter::Converter(const std::string& rawInput) : _rawInput(rawInput) {}

// Destructor
Converter::~Converter() {}

// Copy constructor
Converter::Converter(const Converter& other) : _rawInput(other._rawInput) {}

// Copy assignment operator
Converter& Converter::operator=(const Converter& other) {
    if (this != &other) {
        _rawInput = other._rawInput;
    }
    return *this;
}


void Converter::convertAndPrint() {
    std::cout << "char: ";
    char charValue = toChar();
    if (charValue != '\0')
        std::cout << "'" << charValue << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    int intValue = toInt();
    if (intValue != 0)
        std::cout << intValue << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    float floatValue = toFloat();
    if (floatValue != 0.0f)
        std::cout << floatValue << "f" << std::endl;
    else
        std::cout << "nanf" << std::endl;

    std::cout << "double: ";
    double doubleValue = toDouble();
    if (doubleValue != 0.0)
        std::cout << doubleValue << std::endl;
    else
        std::cout << "nan" << std::endl;
}

char Converter::toChar() {
    if (_rawInput.length() == 1)
        return _rawInput[0];
    else
        return '\0';
}

int Converter::toInt() {
    try {
        return std::atoi(_rawInput.c_str());
    } catch (...) {
        return 0;
    }
}

float Converter::toFloat() {
    try {
        return static_cast<float>(std::atof(_rawInput.c_str()));
    } catch (...) {
        return 0.0f;
    }
}

double Converter::toDouble() {
    try {
        return std::atof(_rawInput.c_str());
    } catch (...) {
        return 0.0;
    }
}

// c_str is used to return a null-terminated character arrays as input to function who expect a c style string.