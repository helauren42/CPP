/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:49:54 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 18:58:59 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brainny = new Brain();
	std::cout << "Dog Default class created\n";
}

Dog::Dog(Dog& originalDog)
: Animal(originalDog)
{
	this->type = originalDog.type;
	this->brainny = new Brain();
	std::cout << "Dog copy class created\n";
}

Dog::~Dog()
{
	delete (this->brainny);
	std::cout << "Dog destructor called\n";
}

Dog&	Dog::operator=(const Dog& copy)
{
	this->type = copy.type;
	return(*this);
}

void	Dog::setTinyIdea()
{
	this->brainny->setTinyIdeas();
}

void	Dog::callBrainOutput()
{
	this->brainny->outputBrainIdeas();
}

void	Dog::makeSound() const
{
	std::cout << "Wrraaaahhfff\n";
}
