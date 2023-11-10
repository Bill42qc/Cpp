#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
	public:
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		FragTrap(const std::string& name);
		void highFivesGuys(void);

		void attack(const std::string& target);
	protected:
	
	private:
		FragTrap();
};