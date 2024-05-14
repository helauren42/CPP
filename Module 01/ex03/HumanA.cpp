/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:44:08 by helauren          #+#    #+#             */
/*   Updated: 2024/02/04 23:21:23 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string n, Weapon &w)
	: name(n), a_Weapon(w)
{}

HumanA::~HumanA(){}

std::string	HumanA::get_weapon(void)
{
	return(this->a_Weapon.getType());
};

void	HumanA::attack(void)
{
	std::cout << this->name << "attacks with " << this->get_weapon() << std::endl;
};

void	HumanA::setName(std::string newName)
{
	this->name = newName;
};

void	HumanA::setWeapon(Weapon& weapon)
{
	this->a_Weapon = weapon;
};
