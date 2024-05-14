/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:44:02 by helauren          #+#    #+#             */
/*   Updated: 2024/02/04 22:08:16 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string s)
	: type(s)
{}

Weapon::~Weapon()
{}

std::string Weapon::getType(void)
{
	return(this->type);
}

void	Weapon::outputType(void)
{
	std::cout << "club : " << this->type << "\n";
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
