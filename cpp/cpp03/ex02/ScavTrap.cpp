#include "ScavTrap.hpp"

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	cout << name << "(ScavTrap) constructor called" << endl << endl;
	hp = 100;
	ep = 50;
	ad = 20;
}
ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s.name)
{
	cout << name << "(ScavTrap) copy constructor called" << endl << endl;
	*this = s;
}
ScavTrap::~ScavTrap()
{
	cout << name << "(ScavTrap) destructor called" << endl << endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &s)
{
	ClapTrap::operator=(s);
	return *this;
}

void ScavTrap::attack(const string &target)
{
	cout << name << "(ScavTrap) attacks " << target <<
		", causing " << ad << " points of damage!" << endl << endl;

}

void ScavTrap::takeDamage(unsigned int amount)
{
	hp -= amount;
	cout << name << "(ScavTrap) takes " << amount << " damage!" << endl;
	cout << hp << " remains." << endl << endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	hp += amount;
	cout << name << "(ScavTrap) repaired by " << amount << "!" << endl;
	cout << hp << " remains." << endl << endl;
}
void ScavTrap::guardGate(void)
{
	cout << name << "(ScavTrap) has enterred in Gate Keeper mode" << endl << endl;
}
