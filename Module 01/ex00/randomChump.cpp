#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	z;

	z.changeName(name);
	z.announce();
}
