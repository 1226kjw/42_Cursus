#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("Jin");
	ClapTrap b(a);
	b = a;
	a.attack("tar");
	a.takeDamage(1);
	a.beRepaired(100);
}

