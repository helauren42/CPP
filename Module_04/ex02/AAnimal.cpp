/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:10:23 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 05:02:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
: type("AAnimal")
{
	std::cout << "AAnimal Default class created\n";
};

AAnimal::AAnimal(std::string newType)
: type(newType)
{
	std::cout << "AAnimal string " << newType << " class created\n";
};

AAnimal::AAnimal(AAnimal& originalAAnimal)
{
	this->type = originalAAnimal.type;
	std::cout << "AAnimal copy class created\n";
};

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called\n";
};

AAnimal&	AAnimal::operator=(const AAnimal& copy)
{
	if(this != &copy)
		*this = copy;
	return(*this);
}

void	AAnimal::makeSound() const
{
	std::cout << "AAnimal sound I guess\n";
};

std::string	AAnimal::getType() const
{
	return(this->type);
};
