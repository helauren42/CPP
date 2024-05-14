/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:49:01 by helauren          #+#    #+#             */
/*   Updated: 2024/02/04 22:55:02 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string s)
	: name(s), b_Weapon(NULL)
{}

HumanB::~HumanB(){}

void	HumanB::attack(void)
{
	if(this->b_Weapon)
		std::cout << this->name << "attacks with " << this->b_Weapon->getType() << std::endl;
	else
		std::cout << this->name << "attacks without weapon, old school just your bare hands is the way to go\n";
}

void	HumanB::setName(std::string newName)
{
	this->name = newName;
};

void	HumanB::setType(std::string newType)
{
	this->b_Weapon->setType(newType);
};

void	HumanB::setWeapon(Weapon& weapon)
{
	this->b_Weapon = &weapon;
};
