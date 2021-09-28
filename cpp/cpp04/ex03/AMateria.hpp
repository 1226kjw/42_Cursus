#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

# include "ICharacter.hpp"

using std::string;
using std::cout;
using std::endl;

class AMateria
{
protected:
	string type;
public:
	AMateria(const string& type);
	AMateria(const AMateria& a);
	virtual ~AMateria();
	const string& getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
