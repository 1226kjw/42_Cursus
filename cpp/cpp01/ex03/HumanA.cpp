#include "HumanA.hpp"

using std::cout;
using std::endl;
using std::string;

HumanA::HumanA(string name, Weapon &weapon) : name(name), weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack(void)
{
	cout << name << "attacks with his " << weapon.getType() << endl;
}
