#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& a);
	~Cure();
	Cure& operator= (const Cure& a);

	Cure* clone() const;
	void use(ICharacter& target);
};

#endif
