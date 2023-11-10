#include "Animal.hpp"
#include "Cat.hpp"

//canonic
Cat::Cat() : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructr called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &other)
{

	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "Cat Copy assignment operator called" << std::endl;
		if(brain)
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

//functions
void Cat::makeSound() const
{
	std::cout << "\"Meeeoooowwww MMMMMEEEEEEOOOOWWWWW \"" << std::endl;
}