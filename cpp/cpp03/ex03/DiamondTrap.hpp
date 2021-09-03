#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& d);
	~DiamondTrap();
	DiamondTrap& operator=(const DiamondTrap& d);
	void attack(const std::string &target);
	void whoAmI(void) const;
};

#endif
