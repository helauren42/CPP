/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:37:07 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 18:57:33 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brainny = new Brain();
	std::cout << "Cat Default class created\n";
}

Cat::Cat(Cat& originalCat)
: Animal(originalCat)
{
	this->type = originalCat.type;
	this->brainny = new Brain();
	std::cout << "Cat copy class created\n";
}

Cat::~Cat()
{
	delete (this->brainny);
	std::cout << "Cat destructor called\n";
}

Cat&	Cat::operator=(const Cat& copy)
{
	this->type = copy.type;
	return(*this);
}

void	Cat::callBrainOutput()
{
	this->brainny->outputBrainIdeas();
}

void	Cat::makeSound() const
{
	std::cout << "Miaaaaaaaooowww" << std::endl;
}
