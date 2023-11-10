#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  public:
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	void makeSound() const;

  protected:
  private:
    Brain *brain;
};