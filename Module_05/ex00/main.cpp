/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:28 by helauren          #+#    #+#             */
/*   Updated: 2024/04/01 12:15:00 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat a;
		std::cout << a;
		Bureaucrat b("Henri", 12);
		std::cout << b;
		Bureaucrat c("BOB", -20);
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cout << "FOUND ERROR : ";
		std::cerr << e.what() << '\n';
	}
}
