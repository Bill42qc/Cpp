#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"

//canonic
Dog::Dog()
	: Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete	brain;

	std::cout << "Dog default destructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "dog Copy assignment operator called" << std::endl;
		brain = new Brain();
	}
	return (*this);
}
//functions
void Dog::makeSound() const
{
	std::cout << "\"WoooOOuufff WooooooOOuffff\"" << std::endl;
}