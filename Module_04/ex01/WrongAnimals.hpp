/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimals.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:58:42 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 18:58:17 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class WrongAnimals
{
		public:
		WrongAnimals();
		WrongAnimals(std::string type);
		WrongAnimals(WrongAnimals& originalWrongAnimals);
		~WrongAnimals();
		WrongAnimals&	operator=(const WrongAnimals& copy);
		void			makeSound() const;
		std::string		getType() const;
	protected:
		std::string	type;
};
