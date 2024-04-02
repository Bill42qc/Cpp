#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

// random to get A B C
Base* generate() {
    srand(static_cast<unsigned int>(time(NULL)));
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

// identifier le type de l'objet //// (uf the pointer can be cast to any of these derived 
// classes, it means the object is of that type.)
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// Surcharge de la fonction identify pour accepter une réf
void identify(Base& p) {
    identify(&p);
}
