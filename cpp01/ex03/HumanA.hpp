#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack();

private:
    std::string _name;
    Weapon &_own_weapon;
};