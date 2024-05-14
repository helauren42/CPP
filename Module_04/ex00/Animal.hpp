/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:23:10 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 00:24:40 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal& originalAnimal);
		virtual				~Animal();
		Animal&				operator=(const Animal& copy);
		virtual void		makeSound() const;
		std::string			getType() const;
	protected:
		std::string	type;
};
