#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
protected:
	std::string name;
	int hp;
	int ep;
	int ad;
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& c);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& c);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int anount);
};

#endif
