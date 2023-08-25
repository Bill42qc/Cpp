#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
    HumanB(std::string name);
    ~HumanB();
    void attack();
    void setWeapon(Weapon &new_weapon);

private:
    std::string _name;
    Weapon     *_own_weapon;
};