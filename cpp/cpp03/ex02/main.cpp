#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a("Jin");
	FragTrap b(a);
	a.attack("tar");
	a.takeDamage(1);
	a.beRepaired(100);
	a.highFivesGuys();
}

