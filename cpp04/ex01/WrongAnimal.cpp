#include "WrongAnimal.hpp"

//canonic form
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	type = "Wr_Unknown";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

//getter
std::string WrongAnimal::getType() const
{
	return (type);
}

 void WrongAnimal::makeSound(void) const
{
	std::cout << "\"Imagine an WrongAnimal sounds of your choice ! \"" << std::endl;
}