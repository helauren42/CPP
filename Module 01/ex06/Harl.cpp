/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:55:52 by helauren          #+#    #+#             */
/*   Updated: 2024/02/06 03:46:25 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string	complainType[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	functions f[4];
	f[0] = &Harl::debug;
	f[1] = &Harl::error;
	f[2] = &Harl::info;
	f[3] = &Harl::warning;

	for (int i = 0; i < 4; i++)
	{
		if(complainType[i].compare(level) == 0)
		{
			while(i < 4)
			{
				(this->*(f[i]))();
				i++;
			}
			return ;
		}
	}
	std::cout << "valid arguments are \"DEBUG\",\"INFO\",\"WARNING\",\"ERROR\" not this crap : " << level;
}


void Harl::debug()
{
	std::cout
		<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!"
		<< std::endl;
}

void Harl::info()
{
	std::cout
		<< "I cannot believe adding extra bacon cost more money."
		<< " You don’t put enough!"
		<< " If you did I would not have to ask for it!"
		<< std::endl;
}

void Harl::warning()
{
	std::cout
		<< "I think I deserve to have some extra bacon for free."
		<< " I’ve been coming here for years and you just started working here last month."
		<< std::endl;
}

void Harl::error()
{
	std::cout
		<< "This is unacceptable, I want to speak to the manager now."
		<< std::endl;
}
