/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 21:31:32 by helauren          #+#    #+#             */
/*   Updated: 2024/02/13 21:14:43 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("Nobody"), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << "Default(Nobody) ClapTrap was created\n";
};

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << name << " ClapTrap was created" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap& copy)
	: _name(copy._name), _hitPoints(10), _energyPoints(10), _attackDamage(10)
{
	std::cout << copy._name << "Copy class ClapTrap was created "  << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " was destroyed\n";
};

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " can't take attack because it is dead" << std::endl;
		return;
	}
	if(this->_energyPoints <= 0)
	{
		std::cout << this->_name << " Can't attack, no energy points left\n";
		return ;
	}
	std::cout << this->_name << " attacked " << target << " and did " << this->_attackDamage << " attack damage\n";
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " can't be hurt anymore as " << this->_name << " is already dead\n";
		return;
	}
	this->_hitPoints -= amount;
	std::cout << this->_name << " was hit and lost " << amount << " hit points\n"; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " can't repair because it is dead" << std::endl;
		return;
	}
	if(this->_energyPoints <= 0)
	{
		std::cout << this->_name << "Can't attack, no energy points left\n";
		return ;
	}
	std::cout << this->_name << " channeled its healing powers and healed " << amount << " hit points\n";
	this->_energyPoints--;
	this->_hitPoints = this->_hitPoints + amount;
}

int	ClapTrap::getHitPoints()
{
	return(this->_hitPoints);
}

// setters

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(int amount)
{
	this->_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(int amount)
{
	this->_energyPoints = amount;	
}

void	ClapTrap::setAttackDamage(int amount)
{
	this->_attackDamage = amount;
}
