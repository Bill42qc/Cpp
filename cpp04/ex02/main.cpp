#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int arraySize = 4;
    Animal* animals[arraySize];

	srand (time(NULL));
    for (int i = 0; i < arraySize / 2; ++i) {
        animals[i] = new Dog();
    }

    for (int i = arraySize / 2; i < arraySize; ++i) {
        animals[i] = new Cat();
    }


  // Create a new Dog using the existing Dog in the array
    Animal* dave = new Dog(*static_cast<Dog*>(animals[1]));
    Animal* billy = new Cat(*static_cast<Cat*>(animals[1]));

	delete dave;
	delete billy;

    // Delete animals
    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

    return 0;
}