#include "Fixed.hpp"

using std::cout;
using std::endl;

const int Fixed::frac_bit = 8;

Fixed::Fixed() : fixed(0)
{
	cout << "Default constructor called" << endl;
}
Fixed::Fixed(Fixed &a)
{
	cout << "Copy constructor called" << endl;
	*this = a;
}
Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed& Fixed::operator= (Fixed &a)
{
	cout << "Assignation operator called" << endl;
	fixed = a.getRawBits();
	return *this;
}

int Fixed::getRawBits(void)
{
	cout << "getRawBits member function called" << endl;
	return fixed;
}

void Fixed::setRawBits(const int raw)
{
	fixed = raw;
}
