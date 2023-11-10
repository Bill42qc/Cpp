#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wr_animal = new WrongAnimal();
	const WrongAnimal *wr_cat = new WrongCat();

	std::cout << "animal type = " << animal->getType() << std::endl;
	std::cout << "dog type = " << dog->getType() << std::endl;
	std::cout << "cat type = " << cat->getType() << std::endl;
	
	std::cout << "Animal sound like: "<< std::endl;
	animal->makeSound();
	std::cout << "Dog sound like: "<< std::endl;
	dog->makeSound();
	std::cout << "Cat sound like: "<< std::endl;
	cat->makeSound();

	std::cout << "wr_animal type = " << wr_animal->getType() << std::endl;
	std::cout << "wr_cat type = " << wr_cat->getType() << std::endl;
	std::cout << "wr_animal sound like: "<< std::endl;
	wr_animal->makeSound();
	std::cout << "wr_cat sound like: "<< std::endl;
	wr_cat->makeSound();


	//free
	delete animal;
	delete cat;
	delete dog;
	delete wr_animal;
	delete wr_cat;
	
	return (0);
}

