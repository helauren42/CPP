/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:44:04 by helauren          #+#    #+#             */
/*   Updated: 2024/02/04 22:07:17 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>

class Weapon
{
	public:
		Weapon(std::string s);
		~Weapon();
		std::string			getType (void);
		void				setType(std::string new_type);
		void	outputType(void);

	private:
		std::string	type;
};

#endif