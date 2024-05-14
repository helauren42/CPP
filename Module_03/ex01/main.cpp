/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:23:24 by helauren          #+#    #+#             */
/*   Updated: 2024/02/09 04:46:27 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	alice_rundown(void)
{
	ScavTrap alice("Alice");

	alice.attack("Bob");
	alice.attack("Chris");
	alice.attack("Diana");
	alice.attack("Elisa");
	alice.attack("Fred");
	alice.attack("Gemma");
	alice.attack("Henry");
	alice.attack("Isabella");
	alice.attack("Jack");
	alice.attack("Kevin");
	alice.attack("Laura");
	alice.attack("Mike");
	alice.guardGate();
}

void	bob_rundown(void)
{
	ScavTrap	bob("Bob");

	while (bob.getHitPoints() > 0)
	{
		bob.takeDamage(20);
		bob.beRepaired(10);
	}
	bob.takeDamage(1);
	bob.guardGate();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Alice's rundown..." << std::endl << std::endl;
	alice_rundown();
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}

// int main()
// {
// 	ClapTrap *c1 = new ClapTrap();
// 	ClapTrap *c2 = new ClapTrap("Zoro");
// 	ClapTrap *c3 = new ClapTrap("AUTO HEALER");

// 	std::cout << std::endl;

// 	c3->beRepaired(50);
	
// 	std::cout << std::endl;

// 	c1->attack("Slime");
// 	c2->attack("Sanji");
// 	c3->attack("Random stranger");

// 	std::cout << std::endl;

// 	c1->takeDamage(80);
// 	c2->takeDamage(5);
// 	c2->takeDamage(5);
// 	c2->takeDamage(5);
// 	c1->takeDamage(5);

// 	std::cout << std::endl;

// 	c3->takeDamage(55);
// 	c3->beRepaired(500);
// 	c3->takeDamage(150);

// 	std::cout << std::endl;

// 	c1->beRepaired(1000);
// 	c2->beRepaired(1);
// 	c3->beRepaired(500);

// 	std::cout << std::endl;

// 	delete (c1);
// 	delete (c2);
// 	delete (c3);
// }
