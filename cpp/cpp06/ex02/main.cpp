#include <iostream>
#include "Identify.hpp"
using std::cout;
using std::string;
using std::endl;

int main()
{
	Base* a = generate();
	identify(a);
	Base& b = *generate();
	identify(b);
}
