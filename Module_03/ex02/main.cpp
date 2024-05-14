/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:23:24 by helauren          #+#    #+#             */
/*   Updated: 2024/02/13 21:16:49 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ScavTrap *c1 = new ScavTrap();
	FragTrap *c2 = new FragTrap("Zoro");
	FragTrap *aux = new FragTrap();
	FragTrap *c3 = new FragTrap(*aux);

	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(50);
	c2->takeDamage(100);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	std::cout << std::endl;

	c1->guardGate();
	c2->highFivesGuys();
	c3->highFivesGuys();

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete aux;
	delete c3;
}

// void	alice_rundown(void)
// {
// 	ScavTrap alice("Alice");

// 	alice.attack("Bob");
// 	alice.attack("Chris");
// 	alice.attack("Diana");
// 	alice.attack("Elisa");
// 	alice.attack("Fred");
// 	alice.attack("Gemma");
// 	alice.attack("Henry");
// 	alice.attack("Isabella");
// 	alice.attack("Jack");
// 	alice.attack("Kevin");
// 	alice.attack("Laura");
// 	alice.attack("Mike");
// 	alice.guardGate();
// }

// void	bob_rundown(void)
// {
// 	ScavTrap	bob("Bob");

// 	while (bob.getHitPoints() > 0)
// 	{
// 		bob.takeDamage(20);
// 		bob.beRepaired(10);
// 	}
// 	bob.takeDamage(1);
// 	bob.guardGate();
// }

// void	jack_rundown(void)
// {
// 	FragTrap	jack("jack");

// 	while (jack.getHitPoints() > 0)
// 	{
// 		jack.takeDamage(20);
// 		jack.beRepaired(10);
// 	}
// 	jack.takeDamage(1);
// 	jack.highFivesGuys();
// }

// int	main(void)
// {
// 	std::cout << std::endl << std::endl << "Performing Alice's rundown..." << std::endl << std::endl;
// 	alice_rundown();
// 	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
// 	bob_rundown();
// 	std::cout << std::endl << std::endl << "Performing Jack's rundown..." << std::endl << std::endl;
// 	jack_rundown();
// }

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
