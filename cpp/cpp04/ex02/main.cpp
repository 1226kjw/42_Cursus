#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


using std::cout;
using std::endl;
using std::string;

int main()
{
	Animal *a = new Cat;
	Animal *b = new Dog;
	a->makeSound();
	b->makeSound();
	delete a;
	delete b;
	
	Dog c;
	Dog d;
	d = c;
	c.tellIdeas();
	d.tellIdeas();

	Cat e;
	Cat f(e);
	e.tellIdeas();
	f.tellIdeas();
}
