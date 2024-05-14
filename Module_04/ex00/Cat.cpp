/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:37:07 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 18:54:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat Default class created\n";
}

Cat::Cat(Cat& originalCat)
: Animal(originalCat)
{
	this->type = originalCat.type;
	std::cout << "Cat copy class created\n";
}

Cat&	Cat::operator=(const Cat& copy)
{
	this->type = copy.type;
	return(*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << "Miaaaaaaaooowww" << std::endl;
}
