#include "Zombie.h"

int main()
{
	int N = 10;
	Zombie *horde = zombieHorde(N, "Bob");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
