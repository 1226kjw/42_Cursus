#include "HumanB.hpp"

using std::cout;
using std::endl;
using std::string;

HumanB::HumanB(string name) : name(name), weapon(0) {}
HumanB::~HumanB() {}

void HumanB::attack(void)
{
	cout << name << "attacks with his ";
	if (!weapon)
		cout << "unarmed hand" << endl;
	else
		cout << weapon->getType() << endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
