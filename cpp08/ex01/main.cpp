#include "Span.hpp"
#include <iostream>

int main() {
    // Create a Span object with a maximum capacity of 4
    Span sp = Span(4);

    // Add numbers to the Span
    sp.addNumber(1);
    sp.addNumber(7);
    sp.addNumber(13);
    sp.addNumber(20);

    // Test shortestSpan and longestSpan
    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
