/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:41:34 by helauren          #+#    #+#             */
/*   Updated: 2024/02/13 21:16:50 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "Default(Nobody) FragTrap was created\n";
}

FragTrap::FragTrap(std::string nameee)
{
	this->_name = nameee;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << this->_name << " FragTrap was created" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
	if(this->_hitPoints <= 0)
		std::cout << this->_name << " can not do highFiveGuys because it is dead\n";
	else if(this->_energyPoints <= 0)
		std::cout << this->_name << " can not do highFiveGuys because it has no more energy to do anything !\n";
	else
		std::cout << this->_name << " is doing highFiveGuys\n";
}
