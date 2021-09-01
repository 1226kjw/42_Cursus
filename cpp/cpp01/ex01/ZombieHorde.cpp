#include "Zombie.hpp"
#include <cstdlib>

Zombie *ZombieHorde(int N, std::string name)
{
	Zombie *z = new Zombie[N];
	for (int i = 0; i < N; i++)
		z[i].setName(name);
	return z;
}
