/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:36:28 by helauren          #+#    #+#             */
/*   Updated: 2024/04/17 13:45:40 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"

int	main(void)
{
	std::cout << "\nTest Bob fails to sign\n\n";
	try
	{
		Bureaucrat Bob("Bob", 6);
		Form		a("VIP doc", 5, 15);
		a.besigned(Bob);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest Bob increments and gets grade too high\n\n";
	try
	{
		Bureaucrat Bob("Bob", 3);
		Form		a("VIP doc", 5, 15);
		Bob.increment(3);
		std::cout << Bob;
		a.besigned(Bob);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest Bob decrements and gets grade too low\n\n";
	try
	{
		Bureaucrat Bob("Bob", 149);
		Form		a("VIP doc", 5, 15);
		Bob.decrement(3);
		std::cout << Bob;
		a.besigned(Bob);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest Bob increments and now can sign\n\n";
	try
	{
		Bureaucrat Bob("Bob", 7);
		Form		a("VIP doc", 5, 15);
		Bob.increment(3);
		std::cout << Bob;
		a.besigned(Bob);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest Bob signs when offered to\n\n";
	try
	{
		Bureaucrat Bob("Bob", 8);
		Form		a("VIP doc", 12, 15);
		std::cout << a;
		a.besigned(Bob);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest Bob signs when offered to same but different\n\n";
	try
	{
		Bureaucrat Bob("Bob", 8);
		Form		a("VIP doc", 12, 15);
		Bob.signForm(a);
		a.besigned(Bob);
		Bob.signForm(a);
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTest Bob can't sign and then upgrades to sign it ! #same but different\n\n";
	try
	{
		Bureaucrat Bob("Bob", 14);
		Form		a("VIP doc", 12, 15);
		Bob.signForm(a);
		Bob.increment(3);
		Bob.signForm(a);
		a.besigned(Bob);
		Bob.signForm(a);
		std::cout << Bob;
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << "Found error : ";
		std::cerr << e.what() << '\n';
	}
}
