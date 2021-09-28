#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("")
{
	cout << "WrongAnimal's default constructor called" << endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
	cout << "WrongAnimal's copy constructor called" << endl;
	type = a.getType();
}
WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal's destructor called" << endl;
}
WrongAnimal& WrongAnimal::operator= (const WrongAnimal& a)
{
	type = a.getType();
	return *this;
}

string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	cout << "Unknown Sound" << endl;
}
