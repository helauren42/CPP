/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:28 by helauren          #+#    #+#             */
/*   Updated: 2024/04/17 15:05:11 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"

int	main(void)
{
	try
	{
		std::cout << "TEST fail form execute, throw error\n\n";
		Bureaucrat Bob("Bob", 3);
		PresidentialPardonForm pres("Becoming President");
		pres.execute(Bob);
	}
	catch(const std::exception& e)
	{
		std::cout << "CAUGHT ERROR:\n";
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\nTEST execute Robot()\n\n";
		Bureaucrat Bob("Bob", 40);
		Bureaucrat signer("signer", 3);
		PresidentialPardonForm pres("Becoming President");
		RobotomyRequestForm robot("Robot attack");
		Bob.executeForm(pres);
		pres.beSigned(signer);
		robot.beSigned(signer);
		Bob.executeForm(robot);
		Bob.executeForm(pres);
	}
	catch(const std::exception& e)
	{
		std::cout << "CAUGHT ERROR:\n";
		std::cerr << e.what() << '\n';
	}

	// try
	// {
	// 	std::cout << "\nTEST execute()\n\n";
	// 	Bureaucrat Bob("Bob", 40);
	// 	Bureaucrat signer("signer", 3);
	// 	PresidentialPardonForm pres("Becoming President");
	// 	RobotomyRequestForm robot("Robot attack");
	// 	Bob.executeForm(pres);
	// 	pres.beSigned(signer);
	// 	robot.beSigned(signer);
	// 	robot.execute(Bob);
	// 	pres.execute(Bob);
	// 	// Bob.executeForm(robot);
	// 	// Bob.executeForm(pres);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << "CAUGHT ERROR:\n";
	// 	std::cerr << e.what() << '\n';
	// }

	try
	{
		std::cout << "\nTEST can_do_it_all_BOB\n\n";
		Bureaucrat can_do_it_all_BOB("can_do_it_all_BOB", 3);
		PresidentialPardonForm pres("Becoming President");
		RobotomyRequestForm robot("Robot attack");
		ShrubberyCreationForm shrubby("Shrubberies in the President's garden");
		can_do_it_all_BOB.signAForm(pres);
		pres.beSigned(can_do_it_all_BOB);
		std::cout << "\n";
		robot.beSigned(can_do_it_all_BOB);
		can_do_it_all_BOB.signAForm(robot);
		std::cout << "\n";
		shrubby.beSigned(can_do_it_all_BOB);
		can_do_it_all_BOB.signAForm(shrubby);
		can_do_it_all_BOB.signAForm(robot);
		robot.beSigned(can_do_it_all_BOB);
		std::cout << "\n";
		can_do_it_all_BOB.executeForm(pres);
		can_do_it_all_BOB.executeForm(robot);
		can_do_it_all_BOB.executeForm(shrubby);
	}
	catch(const std::exception& e)
	{
		std::cout << "CAUGHT ERROR:\n";
		std::cerr << e.what() << '\n';
	}
}
