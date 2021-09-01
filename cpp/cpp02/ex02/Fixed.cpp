#include "Fixed.hpp"

using std::cout;
using std::endl;

const int Fixed::frac_bit = 8;

Fixed::Fixed() : fixed(0)
{
	cout << "Default constructor called" << endl;
}
Fixed::Fixed(const Fixed &a)
{
	cout << "Copy constructor called" << endl;
	*this = a;
}
Fixed::Fixed(const int n)
{
	cout << "Int constructor called" << endl;
	if (n > 0x7fffff)
		cout << "Overflow warning" << endl;
	fixed = n << frac_bit;
}
Fixed::Fixed(const float n)
{
	cout << "Float constructor called" << endl;
	if (n > 0x7fffff)
		cout << "Overflow warning" << endl;
	fixed = roundf(n * (1 << frac_bit));
}
Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed& Fixed::operator= (const Fixed &a)
{
	cout << "Assignation operator called" << endl;
	fixed = a.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return fixed;
}

void Fixed::setRawBits(const int raw)
{
	fixed = raw;
}

float Fixed::toFloat(void) const
{
	return fixed / (float)(1 << frac_bit);
}

int Fixed::toInt(void) const
{
	return fixed >> frac_bit;
}

bool Fixed::operator> (const Fixed &a) const
{
	return toFloat() > a.toFloat();
}
bool Fixed::operator< (const Fixed &a) const
{
	return toFloat() < a.toFloat();
}
bool Fixed::operator>= (const Fixed &a) const
{
	return toFloat() >= a.toFloat();
}
bool Fixed::operator<= (const Fixed &a) const
{
	return toFloat() <= a.toFloat();
}
bool Fixed::operator== (const Fixed &a) const
{
	return toFloat() == a.toFloat();
}
bool Fixed::operator!= (const Fixed &a) const
{
	return toFloat() != a.toFloat();
}
Fixed Fixed::operator+ (const Fixed &a) const
{
	return Fixed(toFloat() + a.toFloat());
}
Fixed Fixed::operator- (const Fixed &a) const
{
	return Fixed(toFloat() - a.toFloat());
}
Fixed Fixed::operator* (const Fixed &a) const
{
	return Fixed(toFloat() * a.toFloat());
}
Fixed Fixed::operator/ (const Fixed &a) const
{
	return Fixed(toFloat() / a.toFloat());
}
Fixed Fixed::operator++ ()
{
	fixed++;
	return *this; 
}
Fixed Fixed::operator++ (int)
{
	Fixed tmp(*this);
	fixed++;
	return tmp;
}
Fixed Fixed::operator-- ()
{
	fixed--;
	return *this;
}
Fixed Fixed::operator-- (int)
{
	Fixed tmp(*this);
	fixed--;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return b;
	else
		return a;
}
const Fixed& Fixed::mix(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return b;
	else
		return a;
}

std::ostream& operator<< (std::ostream& out, const Fixed &a)
{
	out << a.toFloat();
	return out;
}
