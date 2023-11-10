
#include "FragTrap.hpp"

int main ()
{
	FragTrap hero ("hero");
	FragTrap monstre ("monstre");

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
	hero.highFivesGuys();
}