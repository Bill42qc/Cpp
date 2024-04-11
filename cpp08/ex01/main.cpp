#include "Span.hpp"
#include <iostream>

int main() {
    try {
        // Create a Span object with a maximum capacity of 4
        Span sp = Span(4);

        sp.addNumber(1);
        sp.addNumber(7);
        sp.addNumber(13);
        sp.addNumber(20);

        // Test shortestSpan and longestSpan
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

///// following test except to get catch
        std::cout << "Following test is expected to get caught" << std::endl;

    try {
    // Create a Span object with a maximum capacity of 4
    Span sp = Span(4);

    // Add numbers to the Span
    sp.addNumber(1);
    sp.addNumber(7);
    sp.addNumber(13);
    sp.addNumber(20);
    sp.addNumber(2);

    // Test shortestSpan and longestSpan
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
}

    ///// Test avec un span de 10k

    try {

        int wantedSpan = 10000;
        Span sp3 = Span(wantedSpan);

        //populate vector with random value
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        std::vector<int> randomNumbers;
        for (int i = 0; i < wantedSpan; ++i) {
            int randomNumber = std::rand(); 
            randomNumbers.push_back(randomNumber); 
        }
        std::cout << "Size of randomNumbers vector: " << randomNumbers.size() << std::endl;

        //add range populate our Span container following the vector Values
        sp3.addRange(randomNumbers.begin(), randomNumbers.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }



    return 0;
}
