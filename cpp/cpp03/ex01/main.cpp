#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
	ScavTrap a("Jin");
	a.attack("tar");
	a.takeDamage(1);
	a.beRepaired(100);
	a.guardGate();
}

