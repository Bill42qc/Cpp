#include "Animal.hpp"
#include "Dog.hpp"

//canonic
Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructr called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	*this = other;
	std::cout << "Dog Copy constructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "Dog Copy assignment operator called" << std::endl;
	}
	return (*this);
}

//functions
void Dog::makeSound() const
{
	std::cout << "\"WoooOOuufff WooooooOOuffff\"" << std::endl;
}