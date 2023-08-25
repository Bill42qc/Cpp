#include <iostream>
#include "Zombie.hpp"

int main ()
{
    Zombie* un = newZombie("dave");
    un->announce();
    delete(un);
    randomChump("Bill");
}