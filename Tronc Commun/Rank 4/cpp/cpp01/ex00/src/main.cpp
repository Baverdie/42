#include "Zombie.h"

int main()
{
	Zombie *heap = newZombie("Foo");
	heap->announce();
	delete heap;	
	randomChump("Bob");
}
