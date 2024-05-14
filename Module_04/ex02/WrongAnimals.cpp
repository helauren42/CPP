/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimals.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:22:44 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 19:01:29 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimals.hpp"

WrongAnimals::WrongAnimals()
: type("WrongAnimals")
{
	std::cout << "WrongAnimals Default class created\n";
};

WrongAnimals::WrongAnimals(std::string newType)
: type(newType)
{
	std::cout << "WrongAnimals string " << newType << " class created\n";
};

WrongAnimals::WrongAnimals(WrongAnimals& originalWrongAnimals)
{
	this->type = originalWrongAnimals.type;
	std::cout << "WrongAnimals copy class created\n";
};

WrongAnimals::~WrongAnimals()
{
	std::cout << "WrongAnimals destructor called\n";
};

WrongAnimals&	WrongAnimals::operator=(const WrongAnimals& copy)
{
	this->type = copy.type;
	return(*this);
}

void	WrongAnimals::makeSound() const
{
	std::cout << "WrongAnimal's sound I guess\n";
};

std::string	WrongAnimals::getType() const
{
	return(this->type);
};
