#include "Animal.hpp"

//canonic form
Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Unknown";
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{if (this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
	
}

//getter
std::string Animal::getType() const
{
	return (type);
}

 void Animal::makeSound(void) const
{
	std::cout << "\"Imagine an animal sounds of your choice ! \"" << std::endl;
}