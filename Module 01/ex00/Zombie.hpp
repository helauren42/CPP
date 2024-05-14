#pragma once
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	changeName(std::string new_name);
		void	announce(void);
	private:
		std::string name;
};

Zombie*	newZombie(std::string name);
void randomChump( std::string name);