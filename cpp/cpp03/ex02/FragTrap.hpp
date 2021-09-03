#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap& f);
	~FragTrap();
	FragTrap& operator=(const FragTrap& f);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int anount);
	void highFivesGuys(void);
};

#endif
