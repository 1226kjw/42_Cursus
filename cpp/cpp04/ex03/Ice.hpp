#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& a);
	~Ice();
	Ice& operator= (const Ice& a);

	Ice* clone() const;
	void use(ICharacter& target);
};

#endif
