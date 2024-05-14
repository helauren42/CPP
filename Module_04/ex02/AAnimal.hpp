/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:23:10 by helauren          #+#    #+#             */
/*   Updated: 2024/02/24 20:55:15 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal& originalAAnimal);
		virtual				~AAnimal() = 0;
		AAnimal&			operator=(const AAnimal& copy);
		virtual void		makeSound() const = 0;
		std::string			getType() const;
	protected:
		std::string	type;
};
