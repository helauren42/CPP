#include "Zombie.hpp"

int	main()
{
	Zombie *z;
	int		N;

	N = 5;
	z = zombieHorde(N, "hord member");
	for (int i = 0; i < N; i++)
		z[i].announce();
	std::cout << "\n5 zombies should have come out\n\n";
	delete[]z;
	N = -1;
	z = zombieHorde(N, "hord member");
	for (int i = 0; i < N; i++)
		z[i].announce();
	std::cout << "expected 0 zombies\n\n";
	delete[]z;
	return (0);
}