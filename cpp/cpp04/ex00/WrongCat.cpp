#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	cout << "WrongCat's default constructor called" << endl;
	type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& a)
{
	cout << "WrongCat's copy constructor called" << endl;
	*this = a;
}
WrongCat::~WrongCat()
{
	cout << "WrongCat's destructor called" << endl;
}
WrongCat& WrongCat::operator= (const WrongCat& a)
{
	type = a.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	cout << "Yaong" << endl;
}
