#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap default destructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other)
{
    *this = other;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
{
    if (this != &other)
    {
        _name = other._name;
        _pv = other._pv;
        _energy = other._energy;
        _atk_dmg = other._atk_dmg;
        std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    }
    return *this;
}



 // Call ClapTrap's constructor to initialize base class attributes
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
     _pv = 100;
    _energy = 50;
    _atk_dmg = 20;
    std::cout << "ScavTrap " << name << " join game ! (constructor)" << std::endl;
}

void ScavTrap::guardGate()
{
      std::cout << "ScavTrap  enter GUARDGATE MODE !!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(_energy > 0 && _pv > 0)
	{
		_energy--;
		std::cout << "ScavTrap " << _name << " attack " << target << " deal " << _atk_dmg << " hit points !" << std::endl;
		std::cout << "Energy Left : " << _energy << std::endl;
	}
	if(_energy < 1)
		std::cout << "Not enough energy to attack !" << std::endl;
	if(_pv < 1)
		std::cout << "You are dead therefore you cannot atack !" << std::endl;
}