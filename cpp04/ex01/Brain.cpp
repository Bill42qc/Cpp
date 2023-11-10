#include "Brain.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generateRandomString(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charsetSize = sizeof(charset) - 1;

    std::string randomString;

    // Seed the random number generator with the current time
 

    for (int i = 0; i < length; ++i) {
        randomString += charset[std::rand() % charsetSize];
    }

    return randomString;
}

Brain::Brain()
{
	for(int i=0; i < 100; i++)
	{
		ideas[i] = generateRandomString(6);
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	
	// Copy the ideas from the other Dog's brain
	std::cout << "Brain copy operator called" << std::endl;
	*this = other;

}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		std::cout << "Brain Copy assignment operator called" << std::endl;
			for (int i = 0; i < 100; ++i)
	{
		std::cout << "idea # " << i << std::endl;
		std::cout << "idea before copy: " << this->ideas[i] << std::endl;
		std::cout << "other idea # " << i << std::endl;
		std::cout << "other idea : " << other.ideas[i] << std::endl;
		this->ideas[i] = other.ideas[i];
		std::cout << "idea after copy: " << this->ideas[i] << std::endl;
	}
	}
	return (*this);
}

const std::string &Brain::getideas() const 
{
    return *ideas;
}
