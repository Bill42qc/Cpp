#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    *this = other;
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
    if (this != &other)
    {
        _name = other._name;
        _pv = other._pv;
        _energy = other._energy;
        _atk_dmg = other._atk_dmg;
        std::cout << "FragTrap Copy assignment operator called" << std::endl;
    }
    return *this;
}

// Call ClapTrap's constructor to initialize base class attributes
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
     _pv = 100;
    _energy = 100;
    _atk_dmg = 30;
    std::cout << "FragTrap " << name << " join game ! (constructor)" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
      std::cout << "FragTrap  ask for a high five !!!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if(_energy > 0 && _pv > 0)
	{
		_energy--;
		std::cout << "FragTrap " << _name << " attack " << target << " deal " << _atk_dmg << " hit points !" << std::endl;
		std::cout << "Energy Left : " << _energy << std::endl;
	}
	if(_energy < 1)
		std::cout << "Not enough energy to attack !" << std::endl;
	if(_pv < 1)
		std::cout << "You are dead therefore you cannot atack !" << std::endl;
}