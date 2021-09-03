#include "FragTrap.hpp"

using std::cout;
using std::endl;
using std::string;

FragTrap::FragTrap(string name): ClapTrap(name)
{
	cout << name << "(FragTrap) constructor called" << endl << endl;
	hp = 100;
	ep = 100;
	ad = 30;
}
FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f.name)
{
	*this = f;
	cout << name << "(FragTrap) copy constructor called" << endl << endl;
}
FragTrap::~FragTrap()
{
	cout << name << "(FragTrap) destructor called" << endl << endl;
}

FragTrap& FragTrap::operator=(const FragTrap &f)
{
	ClapTrap::operator=(f);
	return *this;
}

void FragTrap::attack(const string &target)
{
	cout << name << "(FragTrap) attacks " << target <<
		", causing " << ad << " points of damage!" << endl << endl;

}

void FragTrap::takeDamage(unsigned int amount)
{
	hp -= amount;
	cout << name << "(FragTrap) takes " << amount << " damage!" << endl;
	cout << hp << " remains." << endl << endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	hp += amount;
	cout << name << "(FragTrap) repaired by " << amount << "!" << endl;
	cout << hp << " remains." << endl << endl;
}

void FragTrap::highFivesGuys(void)
{
	cout << name << "(FragTrap) asks for a high five." << endl << endl;
}
