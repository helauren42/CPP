/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:58:20 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 00:45:21 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimals.hpp"

class WrongCat : public WrongAnimals
{
	public:
		WrongCat();
		WrongCat(WrongCat& originalCat);
		~WrongCat();
		WrongCat&			operator=(const WrongCat& copy);
		void	makeSound() const;
};
