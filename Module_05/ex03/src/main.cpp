/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:28 by helauren          #+#    #+#             */
/*   Updated: 2024/04/25 16:23:59 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/Intern.hpp"

int	main(void)
{
	try
	{
		std::cout << "TEST1\n\n";
		Intern	Bob;
		Bureaucrat	Maestro("Maestro", 5);
		AForm* pres = Bob.makeForm("PresidentialPardon", "something");
		if(pres)
		{
			pres->beSigned(Maestro);
			pres->execute(Maestro);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "CAUGHT ERROR:\n";
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "TEST1\n\n";
		Intern	Bob;
		Bureaucrat	Maestro("Maestro", 5);
		AForm* pres = Bob.makeForm("PresidentialPardon", "something");
		if(pres)
		{
			pres->beSigned(Maestro);
			pres->execute(Maestro);
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "CAUGHT ERROR:\n";
		std::cerr << e.what() << '\n';
	}
}
