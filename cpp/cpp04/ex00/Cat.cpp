#include "Cat.hpp"

Cat::Cat()
{
	cout << "Cat's default constructor called" << endl;
	type = "Cat";
}
Cat::Cat(const Cat& a)
{
	cout << "Cat's copy constructor called" << endl;
	*this = a;
}
Cat::~Cat()
{
	cout << "Cat's destructor called" << endl;
}
Cat& Cat::operator= (const Cat& a)
{
	type = a.getType();
	return *this;
}

void Cat::makeSound() const
{
	cout << "Yaong" << endl;
}
