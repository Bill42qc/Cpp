#include <iostream>

int main (int ac, char ** av)
{
if (ac == 1)
    std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std ::endl;
if (ac >= 2)
{
    for(int i=1;i != ac; i++)
    {
        for(int j=0; av[i][j] != '\0';j++)
            std::cout << (char)toupper(av[i][j]);
    }
     std::cout << std ::endl;
}
return(0);
}
