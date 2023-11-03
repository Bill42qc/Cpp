#include "ClapTrap.hpp"

//default construcor
	ClapTrap::ClapTrap() 
	{
		std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
	}
// default destructor
	ClapTrap::~ClapTrap()
	{
		std::cout << "ClapTrap " << _name << " quit the game (destructor)" << std::endl;
	}

// Constructeur avec initialisation des attributs
   ClapTrap::ClapTrap(const  std::string& name) : _name(name), _pv(10), _energy(10), _atk_dmg(0)
    {
        std::cout << "ClapTrap " << _name << " join game (constructor)" << std::endl;
    }

// copy constructor
	ClapTrap::ClapTrap(const ClapTrap &other) 
{
	*this = other;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

// = operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        _name = other._name;
        _pv = other._pv;
        _energy = other._energy;
        _atk_dmg = other._atk_dmg;
        std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if(_energy > 0 && _pv > 0)
	{
		_energy--;
		std::cout << "ClapTrap " << _name << " attack " << target << " deal " << _atk_dmg << " hit points !" << std::endl;
		std::cout << "Energy Left : " << _energy << std::endl;
	}
	if(_energy < 1)
		std::cout << "Not enough energy to attack !" << std::endl;
	if(_pv < 1)
		std::cout << "You are dead therefore you cannot atack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
		_pv -= amount;
		if(_pv < 0)
			_pv =0;
		std::cout << "ClapTrap " << _name << " take " << amount << " hit points. remaining health : " << _pv << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energy > 0 && _pv > 0)
	{
		_pv += amount;
		_energy--;
		std::cout << "ClapTrap " << _name << " regenerate " << amount << " life . remaining health : " << _pv << std::endl;
		std::cout << "Energy Left : " << _energy << std::endl;
	}
	if(_energy < 1)
		std::cout << "Not enough energy to repair yourself !" << std::endl;
	if(_pv < 1)
		std::cout << "You are dead therefore you cannot repair !" << std::endl;
	
}
