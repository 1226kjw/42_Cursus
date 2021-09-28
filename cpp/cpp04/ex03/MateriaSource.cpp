#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		source[i] = 0;
}
MateriaSource::MateriaSource(const MateriaSource& a)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
		source[i] = a.source[i]->clone();
	}
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (source[i])
			delete source[i];
}
MateriaSource& MateriaSource::operator= (const MateriaSource& a)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
		source[i] = a.source[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* newa)
{
	for (int i = 0; i < 4; i++)
		if (source[i] == 0)
		{
			source[i] = newa;
			return ;
		}
}
AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
		if (source[i] && source[i]->getType() == type)
			return source[i]->clone();
	return 0;
}
