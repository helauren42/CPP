/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 00:38:00 by helauren          #+#    #+#             */
/*   Updated: 2024/02/09 04:59:57 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "Basic ScavTrap";
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "Default(Basic ScavTrap) ScavTrap constructor called \n";
};

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << this->_name << "Custom ScavTrap constructor called \n";
};

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is a ScavTrap and can't take attack because it is dead" << std::endl;
		return;
	}
	if(this->_energyPoints <= 0)
	{
		std::cout << this->_name << " is a ScavTrap and can't attack because no energy points are left\n";
		return ;
	}
	std::cout << this->_name << " is a ScavTrap, attacked " << target << " and did " << this->_attackDamage << " attack damage\n";
	this->_energyPoints--;
}

void    ScavTrap::guardGate()
{
    if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is a ScavTrap and can't guard guate, whatever that is, because it is dead" << std::endl;
		return;
	}
	std::cout << this->_name << " is a ScavTrap and is doing guard guate" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << " ScavTrap destructor called \n";
};
