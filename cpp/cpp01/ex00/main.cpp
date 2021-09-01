#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie z;
	z.announce();

	randomChump("11111");

	Zombie *nz = newZombie("22222");
	nz->announce();
	delete(nz);
}
