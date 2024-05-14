/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:23:24 by helauren          #+#    #+#             */
/*   Updated: 2024/02/08 23:55:18 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap *c1 = new ClapTrap();
	ClapTrap *c2 = new ClapTrap("Zoro");
	ClapTrap *c3 = new ClapTrap("AUTO HEALER");

	std::cout << std::endl;

	c3->beRepaired(50);
	
	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Random stranger");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c1->takeDamage(5);

	std::cout << std::endl;

	c3->takeDamage(55);
	c3->beRepaired(500);
	c3->takeDamage(150);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(500);

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
}

