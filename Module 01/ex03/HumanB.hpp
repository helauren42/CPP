/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:55 by helauren          #+#    #+#             */
/*   Updated: 2024/02/04 22:53:57 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

// class Weapon;

class HumanB
{
	public:
		HumanB(std::string s);
		~HumanB();
		void	attack(void);
		void	setName(std::string newName);
		void	setWeapon(Weapon& weapon);
		void	setType(std::string newType);

	private:
		std::string	name;
		Weapon		*b_Weapon;
};

#endif