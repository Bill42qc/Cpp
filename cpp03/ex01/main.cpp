
#include "ScavTrap.hpp"

int main ()
{
	ScavTrap hero ("hero");
	ScavTrap monstre ("monstre");

	hero.attack("monstre");
	monstre.attack("monstre");
	monstre.takeDamage(3);
	monstre.beRepaired(3);
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.attack("monstre");
	hero.beRepaired(3);
	hero.guardGate();
	monstre.takeDamage(8);
	monstre.beRepaired(18);
}