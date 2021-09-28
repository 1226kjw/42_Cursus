#include "Animal.hpp"

Animal::Animal(): type("")
{
	cout << "Animal's default constructor called" << endl;
}
Animal::Animal(const Animal& a)
{
	cout << "Animal's copy constructor called" << endl;
	type = a.getType();
}
Animal::~Animal()
{
	cout << "Animal's destructor called" << endl;
}
Animal& Animal::operator= (const Animal& a)
{
	type = a.getType();
	return *this;
}

string Animal::getType() const
{
	return type;
}
