/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 03:23:08 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 01:08:35 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>
#include <cstdio>

#include <sstream>

Brain::Brain()
{
	std::string			buffer;
	std::stringstream	ss;

	for (int i = 0; i < 100; i++)
	{
		ss << i;
		buffer = ss.str();
		ss.str("");
		this->ideas[i] = "Gigantic idea ";
		this->ideas[i] += buffer;
	}
	std::cout << "Brain default constructor called \n";
}

Brain::Brain(Brain& originalBrain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = originalBrain.ideas[i];
	std::cout << "Brain copy constructor called \n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called \n";
}

Brain&	Brain::operator=(const Brain& copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return(*this);
};

void	Brain::outputBrainIdeas()
{
	for(int i = 0; i < 99; i++)
	{
		std::cout << "Idea " << i << " = ";
		std::cout << this->ideas[i] << "\n";
	}
}

void	Brain::setTinyIdeas()
{
	for(int i = 0; i < 99; i++)
	{
		this->ideas[i] = "Tiny idea";
	}
}
