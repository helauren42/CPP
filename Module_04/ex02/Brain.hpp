/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:41:29 by helauren          #+#    #+#             */
/*   Updated: 2024/02/22 00:59:38 by helauren         ###   ########.fr       */
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
		std::string ideas[100];
};
