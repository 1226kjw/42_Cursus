#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>

# include "ICharacter.hpp"
# include "AMateria.hpp"

using std::string;

class Character : public ICharacter
{
private:
	string name;
	AMateria *inven[4];
public:
	Character(std::string name);
	Character(const Character& a);
	~Character();
	Character& operator= (const Character& a);

	const string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
