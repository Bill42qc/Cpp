#include "Weapon.hpp"

Weapon::Weapon(std::string 	newType)
{
    this->_type = newType;
}

Weapon::~Weapon(){};

const std::string&   Weapon::getType()
{
    return(this->_type);
}

void    Weapon::setType(std::string type)
{
    _type = type;
}