#include "AMateria.hpp"

AMateria::AMateria(const string& type) : type(type) {}
AMateria::AMateria(const AMateria& a) : type(a.type) {}
AMateria::~AMateria() {}
const string& AMateria::getType() const
{
	return type;
}
void AMateria::use(ICharacter& target)
{
	cout << "*use amateria to " << target.getName() << " *" << endl;
}
