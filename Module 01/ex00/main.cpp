#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z;

	z = newZombie("HEAP ZOMBIE");
	z->announce();
	delete (z);
	randomChump("STACK ZOMBIE");
	return (0);
}
