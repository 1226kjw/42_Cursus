#include "ClapTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ClapTrap::ClapTrap(string name) : name(name), hp(10), ep(10), ad(0)
{
	cout << this->name << " : Constructor(string) called" << endl << endl;
}
ClapTrap::ClapTrap(ClapTrap& c)
{
	*this = c;
	cout << this->name << " : Constructor(copy) called" << endl << endl;
}
ClapTrap::~ClapTrap()
{
	cout << this->name << " : Destructor called" << endl << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	name = c.name;
	hp = c.hp;
	ep = c.ep;
	ad = c.ad;
	cout << this->name << " : Assignation operator called" << endl << endl;
	return *this;
}

void ClapTrap::attack(const string &target)
{
	cout << "ClapTrap " << name << " attacks " << target <<
		", causing " << ad << " points of damage!" << endl << endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	hp -= amount;
	cout << "ClapTrap " << name << " takes " << amount << " damage!" << endl;
	cout << hp << " remains." << endl << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hp += amount;
	cout << "ClapTrap " << name << " repaired by " << amount << "!" << endl;
	cout << hp << " remains." << endl << endl;
}
