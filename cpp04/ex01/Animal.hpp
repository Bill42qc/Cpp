#pragma once
#include <iostream>
#include"Brain.hpp"

class Animal
{
  public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	std::string getType() const;
	virtual void makeSound() const;

  protected:
	std::string type;

  private:
};