#pragma once

#include <string>
#include <iostream>

// Déclaration de la classe de base
class Base {
public:
    virtual ~Base() {} // Destructeur virtuel public
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// Déclaration des fonctions
Base* generate();
void identify(Base* p);
void identify(Base& p);