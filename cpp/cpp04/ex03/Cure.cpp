#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure& a) : AMateria(a) {}
Cure::~Cure() {}
Cure& Cure::operator= (const Cure& a)
{
	type = a.type;
	return *this;
}

Cure* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
