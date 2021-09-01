#include "Zombie.hpp"

Zombie *ZombieHorde(int N, std::string name);

int main()
{
	int n = 10;
	Zombie *z;
	z = ZombieHorde(n, "jinukim");

	for (int i = 0; i < n; i++)
		z[i].announce();

	delete[](z);

}
