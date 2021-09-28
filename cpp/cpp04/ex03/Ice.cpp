#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& a) : AMateria(a) {}
Ice::~Ice() {}
Ice& Ice::operator= (const Ice& a)
{
	type = a.type;
	return *this;
}

Ice* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
