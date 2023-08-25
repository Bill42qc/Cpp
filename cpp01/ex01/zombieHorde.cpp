#include <iostream>
#include "Zombie.hpp"

// Allouer un tableau dynamique de N objets Zombie en une seule allocation
// Initialiser les zombies avec le nom passé en paramètre
// Retourner un pointeur vers le premier zombie du tableau
Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; ++i)
        horde[i] = Zombie(name);

    return horde;
}