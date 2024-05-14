/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:10:23 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 01:11:00 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
: type("Animal")
{
	std::cout << "Animal Default class created\n";
};

Animal::Animal(std::string newType)
: type(newType)
{
	std::cout << "Animal string " << newType << " class created\n";
};

Animal::Animal(Animal& originalAnimal)
{
	this->type = originalAnimal.type;
	std::cout << "Animal copy class created\n";
};

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
};

Animal&	Animal::operator=(const Animal& copy)
{
	if(this != &copy)
		*this = copy;
	return(*this);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound I guess\n";
};

std::string	Animal::getType() const
{
	return(this->type);
};

