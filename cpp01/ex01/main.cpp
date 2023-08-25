#include <iostream>
#include "Zombie.hpp"

int main ()
{
    int zombie_nbr = 8;
    std::string default_name = "mort-vivant";

    Zombie *zombies = zombieHorde(zombie_nbr, default_name);
    for(int i=0 ; i < zombie_nbr; i++ )
        zombies->announce();
    delete[] zombies;
    
    return(0);
}