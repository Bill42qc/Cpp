#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::~HumanA(){};

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _own_weapon(weapon) {}


void HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_own_weapon.getType() << std::endl;
}

