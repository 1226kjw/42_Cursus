#include "Zombie.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Zombie::Zombie() : name("default") {}
Zombie::Zombie(string name) : name(name) {}
Zombie::~Zombie()
{
	callname();
	cout << "Destructor called" << endl;
}

void Zombie::callname(void)
{
	cout << std::setw(15) << std::left << "<" + name + ">";
}

void Zombie::announce(void)
{
	callname();
	cout << "BraiiiiiiinnnzzzZ..." << endl;
}
