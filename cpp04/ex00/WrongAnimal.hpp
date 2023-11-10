#pragma once
#include <iostream>

class WrongAnimal
{
  public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType() const;
//on enleve le mot cle virtuel a la ft makeSound(), ainsi la function ne peut plus etre substituée
	/* virtual */void makeSound() const;

  protected:
	std::string type;

  private:
};