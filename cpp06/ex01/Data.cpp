#include "Data.hpp"

Data::Data() : intValue(0), floatValue(0.0f), stringValue("") {}

Data::~Data() {}

Data::Data(const Data& other) : intValue(other.intValue), floatValue(other.floatValue), stringValue(other.stringValue) {}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        intValue = other.intValue;
        floatValue = other.floatValue;
        stringValue = other.stringValue;
    }
    return *this;
}

int Data::getIntValue() const {
    return intValue;
}

float Data::getFloatValue() const {
    return floatValue;
}

std::string Data::getStringValue() const {
    return stringValue;
}

void Data::setIntValue(int value) {
    intValue = value;
}

void Data::setFloatValue(float value) {
    floatValue = value;
}

void Data::setStringValue(const std::string& value) {
    stringValue = value;
}


uintptr_t serialize( Data* ptr) {
    // Cast  pointer to uintptr_t
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    // Cast  uintptr_t  to Data pointer
    return reinterpret_cast<Data*>(raw);
}

