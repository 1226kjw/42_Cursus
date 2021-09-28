#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>

# include "IMateriaSource.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *source[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& a);
	~MateriaSource();
	MateriaSource& operator= (const MateriaSource& a);
	
	void learnMateria(AMateria* newa);
	AMateria* createMateria(const std::string& type);
};

#endif
