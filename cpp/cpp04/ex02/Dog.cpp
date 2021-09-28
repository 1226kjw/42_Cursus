#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog's default constructor called" << endl;
	type = "Dog";
	b = new Brain;
}
Dog::Dog(const Dog& a)
{
	cout << "Dog's copy constructor called" << endl;
	b = new Brain;
	*this = a;
}
Dog::~Dog()
{
	cout << "Dog's destructor called" << endl;
	delete b;
}
Dog& Dog::operator= (const Dog& a)
{
	type = a.type;
	*b = *a.b;
	return *this;
}

void Dog::makeSound() const
{
	cout << "Mung" << endl;
}

void Dog::tellIdeas() const
{
	b->tellIdeas();
}
