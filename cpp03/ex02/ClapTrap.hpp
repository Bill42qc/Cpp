#pragma once
#include <iostream>

/// orthodox canonical form : default empty constructor, defaut destructor, = operator overload, copy constructor
class ClapTrap
{
	public:

		ClapTrap();  //constructeur
		virtual ~ClapTrap(); //destructeur
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:

		std::string _name;				//name of the player
		int _pv;						//point de vie
		int _energy;					//point denergie
		int _atk_dmg;					//atk damage

	private:
	



};