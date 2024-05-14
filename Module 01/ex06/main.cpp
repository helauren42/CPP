/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:50:11 by helauren          #+#    #+#             */
/*   Updated: 2024/02/06 03:15:43 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	Karen;

	if(ac == 1)
	{
		std::cout << "KAREN: YOU NEED TO PASS SOME FUCKING ARGUMENTS\n";
		return (1);
	}
	for (int i = 1; av[i]; i++)
		Karen.complain(av[i]);
	return (0);
}
