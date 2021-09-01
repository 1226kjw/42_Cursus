#include "Zombie.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Zombie::Zombie() : name("") {}
Zombie::Zombie(string name) : name(name) {}
Zombie::~Zombie()
{
	callname();
	cout << "Destructor called" << endl;
}

void Zombie::callname(void)
{
	cout.setf(std::ios::left);
	cout << std::setw(15) << "<" + name + ">";
}

void Zombie::announce(void)
{
	callname();
	cout << "BraiiiiiiinnnzzzZ..." << endl;
}

void Zombie::setName(string name)
{
	this->name = name;
}
