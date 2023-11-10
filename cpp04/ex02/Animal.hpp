#pragma once
#include <iostream>
#include"Brain.hpp"


// Pour rendre la classe Animal non instanciable, vous pouvez la transformer en une 
// classe abstraite en ajoutant au moins une fonction virtuelle pure (une fonction 
// virtuelle avec le signe = 0). Cela rendra impossible la création d'instances de la 
// classe Animal directement.

class Animal
{
  public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	std::string getType() const;
	virtual void makeSound() const = 0; // Pure virtual function

  protected:
	std::string type;

  private:
};