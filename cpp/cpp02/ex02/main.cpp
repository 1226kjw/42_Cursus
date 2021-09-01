#include <iostream>
#include "Fixed.hpp"

using std::cout;
using std::endl;

int main()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;

	cout << b << endl;

	cout << Fixed::mix(a, b) << endl;
	cout << Fixed::max(a, b) << endl;
}
