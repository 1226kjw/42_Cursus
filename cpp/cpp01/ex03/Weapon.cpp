#include "Weapon.hpp"

using std::string;

Weapon::Weapon(string type) : type(type) {}
Weapon::Weapon() : type(NULL) {}
Weapon::~Weapon() {}

const string &Weapon::getType(void)
{
	return type;
}

void Weapon::setType(string type)
{
	this->type = type;
}
