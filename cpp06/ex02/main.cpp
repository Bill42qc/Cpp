#include "Base.hpp"

int main() {
    // Test 1: Generating a random object and identifying its type
    std::cout << "Test 1: Generating a random object and identifying its type" << std::endl;
    Base* obj1 = generate();
    std::cout << "Actual: ";
    identify(obj1);
    std::cout << "Expected: A, B, or C (randomly generated)" << std::endl;

    // Testing the function overload with a reference
    std::cout << "\nTest 2: Identifying the type using function overload with a reference" << std::endl;
    std::cout << "Actual: ";
    identify(*obj1);
    std::cout << "Expected: A, B, or C (same type as Test 1)" << std::endl;

    delete obj1; // Freeing dynamically allocated memory

    // Test 3: Creating an instance of class A and identifying its type
    std::cout << "\nTest 3: Creating an instance of class A and identifying its type" << std::endl;
    A a;
    std::cout << "Actual: ";
    identify(&a);
    std::cout << "Expected: A" << std::endl;

    // Test 4: Creating an instance of class B and identifying its type
    std::cout << "\nTest 4: Creating an instance of class B and identifying its type" << std::endl;
    B b;
    std::cout << "Actual: ";
    identify(&b);
    std::cout << "Expected: B" << std::endl;

    // Test 5: Creating an instance of class C and identifying its type
    std::cout << "\nTest 5: Creating an instance of class C and identifying its type" << std::endl;
    C c;
    std::cout << "Actual: ";
    identify(&c);
    std::cout << "Expected: C" << std::endl;

    return 0;
}
