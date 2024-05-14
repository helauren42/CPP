/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:41:29 by helauren          #+#    #+#             */
/*   Updated: 2024/02/24 21:00:32 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain& originalBrain);
		~Brain();
		void	outputBrainIdeas();
		void	setTinyIdeas();
		Brain&	operator=(const Brain& copy);
	private:
		std::string ideas[100];
};
