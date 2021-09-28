#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Dog();
	const Animal* j = new Cat();

	cout << "i(Dog): " << i->getType() << endl;
	cout << "j(Cat): " << j->getType() << endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	const WrongAnimal *wrongmeta = new WrongAnimal();
	const WrongAnimal *wrongi = new WrongCat();

	cout << "wrongmeta(WrongAnimal): " << wrongmeta->getType() << endl;
	cout << "wrongi(WrongCat): " << wrongi->getType() << endl;
	
	wrongmeta->makeSound();
	wrongi->makeSound();
}
