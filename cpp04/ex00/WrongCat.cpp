#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//canonic
WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructr called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		std::cout << "WrongCat Copy assignment operator called" << std::endl;
	}
	return (*this);
}

//functions
void WrongCat::makeSound() const
{
	std::cout << "\"Meeeoooowwww MMMMMEEEEEEOOOOWWWWW \"" << std::endl;
}