#pragma once

#include <string>

class Data {
public:

    Data();
    Data(const Data& other); 
    Data& operator=(const Data& other); 
    ~Data(); 

    int getIntValue() const;
    float getFloatValue() const;
    std::string getStringValue() const;
    void setIntValue(int value);
    void setFloatValue(float value);
    void setStringValue(const std::string& value);

private:
    int intValue;
    float floatValue;
    std::string stringValue;
};

uintptr_t serialize(Data* ptr);
 Data* deserialize(uintptr_t raw);
