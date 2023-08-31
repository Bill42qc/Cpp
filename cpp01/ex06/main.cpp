#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "Use like this : ./HarlFilter <level_of_complaint> " << std::endl;
        return (1);
    }
    harl.complain(av[1]);
    return 0;
}