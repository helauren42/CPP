/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:43:52 by helauren          #+#    #+#             */
/*   Updated: 2024/02/04 23:01:04 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

// class Weapon;

class HumanA
{
	public:
		HumanA(std::string n, Weapon &w);
		~HumanA();
		void		attack(void);
		void		setName(std::string newName);
		void		setWeapon(Weapon& weapon);
		std::string	get_weapon(void);

	private:
		std::string	name;
		Weapon&		a_Weapon;
};

#endif