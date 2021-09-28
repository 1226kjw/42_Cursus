#include "Cat.hpp"

Cat::Cat()
{
	cout << "Cat's default constructor called" << endl;
	type = "Cat";
	b = new Brain;
}
Cat::Cat(const Cat& a)
{
	cout << "Cat's copy constructor called" << endl;
	b = new Brain;
	*this = a;
}
Cat::~Cat()
{
	cout << "Cat's destructor called" << endl;
	delete b;
}
Cat& Cat::operator= (const Cat& a)
{
	type = a.type;
	*b = *a.b;
	return *this;
}

void Cat::makeSound() const
{
	cout << "Yaong" << endl;
}

void Cat::tellIdeas() const
{
	b->tellIdeas();
}
