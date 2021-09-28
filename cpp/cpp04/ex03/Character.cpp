#include "Character.hpp"

Character::Character(string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inven[i] = 0;
}
Character::Character(const Character& a)
{
	*this = a;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (inven[i])
			delete inven[i];
}
Character& Character::operator= (const Character& a)
{
	name = a.name;
	for (int i = 0; i < 4; i++)
	{
		if (inven[i])
			delete inven[i];
		if (a.inven[i])
			inven[i] = a.inven[i]->clone();
		else
			inven[i] = 0;
	}
	return *this;
}

const string& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (inven[i] == 0)
		{
			inven[i] = m;
			return ;
		}
}

void Character::unequip(int idx)
{
	if (0 <= idx && idx <= 4 && inven[idx])
		inven[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx <= 4 && inven[idx])
		inven[idx]->use(target);
}
