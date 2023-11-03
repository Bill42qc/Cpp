#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		ScavTrap(const std::string& name);
		void guardGate();

		void attack(const std::string& target);
	protected:
	
	private:
		ScavTrap();
};