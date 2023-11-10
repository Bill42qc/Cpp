#include "Animal.hpp"
#include "Cat.hpp"

//canonic
Cat::Cat()
	: Animal()
{
	type = "Cat";
	std::cout << "Cat default constructr called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << "Cat Copy constructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "Cat Copy assignment operator called" << std::endl;
	}
	return (*this);
}

//functions
void Cat::makeSound() const
{
	std::cout << "\"Meeeoooowwww MMMMMEEEEEEOOOOWWWWW \"" << std::endl;
}