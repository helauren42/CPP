/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:52:46 by helauren          #+#    #+#             */
/*   Updated: 2024/07/04 19:01:00 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarTypes.hpp"

int	main(int ac, char **av)
{
	ScalarTypes	A;

	if(ac != 2)
	{
		std::cout << "You need to pass one argument\n";
		return (1);
	}
	std::string	str = av[1];
	if(str.length() == 0)
	{
		std::cout << "string is empty can't convert nothing\n";
		return (1);
	}
	if(A.isValidInput(av[1]) == false)
	{
		std::cout << "Input is not valid\n";
		return (1);
	}
	A.convert(av[1]);
	std::cout << A;
	return (0);
}
