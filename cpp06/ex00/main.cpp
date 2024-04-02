#include <iostream>
#include "Converter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <raw_input>" << std::endl;
        return 1;
    }

    Converter converter(argv[1]);
    converter.convertAndPrint();

    return 0;
}
