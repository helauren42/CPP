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
		~Zombie();
		void	changeName(std::string new_name);
		void	announce(void);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );
