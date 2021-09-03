#include "DiamondTrap.hpp"

using std::cout;
using std::endl;
using std::string;

DiamondTrap::DiamondTrap(string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
	cout << name << "(DiamondTrap) constructor called" << endl << endl;
	hp = FragTrap::hp;
	ep = ScavTrap::ep;
	ad = FragTrap::ad;
}
DiamondTrap::DiamondTrap(const DiamondTrap& d): ClapTrap(d.name + "_clap_name"), FragTrap(d.name), ScavTrap(d.name)
{
	cout << name << "(DiamondTrap) copy constructor called" << endl << endl;
	*this = d;
}
DiamondTrap::~DiamondTrap()
{
	cout << name << "(DiamondTrap) destructor called" << endl << endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
	cout << name << "(DiamondTrap) assignation operator called" << endl << endl;
	name = d.name;
	ClapTrap::name = d.ClapTrap::name;
	hp = d.hp;
	ep = d.ep;
	ad = d.ad;
	return *this;
}
void DiamondTrap::attack(const string& target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI(void) const
{
	cout << "Who Am I : ";
	cout << name << "(DiamondTrap), " << ClapTrap::name << "(ClapTrap)" << endl << endl;
}
