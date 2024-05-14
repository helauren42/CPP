/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:49:54 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 18:54:35 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Default class created\n";
}

Dog::Dog(Dog& originalDog)
: Animal(originalDog)
{
	this->type = originalDog.type;
	std::cout << "Dog copy class created\n";
}

Dog&	Dog::operator=(const Dog& copy)
{
	this->type = copy.type;
	return(*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << "Wrraaaahhfff\n";
}
