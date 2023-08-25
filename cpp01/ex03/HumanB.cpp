#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string name) : _name(name) {};

HumanB::~HumanB(){};

void HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << this->_own_weapon->getType() << std::endl;
}

void HumanB::setWeapon (Weapon &new_weapon)
{
    this->_own_weapon = &new_weapon;
}