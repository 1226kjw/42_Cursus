#include "Dog.hpp"

Dog::Dog()
{
	cout << "Dog's default constructor called" << endl;
	type = "Dog";
}
Dog::Dog(const Dog& a)
{
	cout << "Dog's copy constructor called" << endl;
	*this = a;
}
Dog::~Dog()
{
	cout << "Dog's destructor called" << endl;
}
Dog& Dog::operator= (const Dog& a)
{
	type = a.getType();
	return *this;
}

void Dog::makeSound() const
{
	cout << "Mung" << endl;
}
