#include "ClapTrap.hpp"

int main ()
{
	ClapTrap hero ("hero");
	ClapTrap monstre ("monstre");

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
	monstre.takeDamage(8);
	monstre.beRepaired(18);
}