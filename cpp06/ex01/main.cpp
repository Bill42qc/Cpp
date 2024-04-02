#include <iostream>
#include "Data.hpp"

int main() {
    // Create a Data object
    Data data;
    data.setIntValue(42);
    data.setFloatValue(3.14f);
    data.setStringValue("Hello, World!");

    // Print data before serialization
    std::cout << "Data before serialization:" << std::endl;
    std::cout << "Int Value: " << data.getIntValue() << std::endl;
    std::cout << "Float Value: " << data.getFloatValue() << std::endl;
    std::cout << "String Value: " << data.getStringValue() << std::endl;

    // Serialize
    uintptr_t serializedPtr = serialize(&data);

    // Deserialize
    Data* deserializedPtr = deserialize(serializedPtr);

    // Print data after deserialization
    std::cout << "\nData after deserialization:" << std::endl;
    std::cout << "Int Value: " << deserializedPtr->getIntValue() << std::endl;
    std::cout << "Float Value: " << deserializedPtr->getFloatValue() << std::endl;
    std::cout << "String Value: " << deserializedPtr->getStringValue() << std::endl;

    // Compare data 
    bool isLegit = (deserializedPtr->getIntValue() == data.getIntValue()) &&
                   (deserializedPtr->getFloatValue() == data.getFloatValue()) &&
                   (deserializedPtr->getStringValue() == data.getStringValue());

    // Verify
    if (deserializedPtr != NULL && isLegit) {
        std::cout << "\nSerialization and deserialization successful!" << std::endl;
    } else {
        std::cout << "\nSerialization and deserialization failed!" << std::endl;
    }

    return 0;
}
