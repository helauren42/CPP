/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:24:53 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 18:55:07 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default class created\n";
}

WrongCat::WrongCat(WrongCat& originalWrongCat)
: WrongAnimals(originalWrongCat)

{
	this->type = originalWrongCat.type;
	std::cout << "WrongCat copy class created\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& copy)
{
	this->type = copy.type;
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong cat should not output this sound ewruiewhoew\n";
}
