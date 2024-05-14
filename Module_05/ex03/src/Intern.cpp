/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:12:49 by helauren          #+#    #+#             */
/*   Updated: 2024/05/07 17:49:22 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.hpp"
#include "../incl/AForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/ShrubberyCreationForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Intern::Intern()
{
	makeFormFunctions[0] = &Intern::makePresidentialPardon;
	makeFormFunctions[1] = &Intern::makeRobotmyRequest;
	makeFormFunctions[2] = &Intern::makeShrubberyCreation;
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

/* ----------------------------- METHODS ------------------------------- */

AForm*	Intern::makePresidentialPardon(std::string target)
{
	PresidentialPardonForm *pres = new PresidentialPardonForm(target);
	return ((AForm*)pres);
}

AForm*	Intern::makeRobotmyRequest(std::string target)
{
	RobotomyRequestForm *ret = new RobotomyRequestForm(target);
	return ((AForm*)ret);
}

AForm*	Intern::makeShrubberyCreation(std::string target)
{
	ShrubberyCreationForm *ret = new ShrubberyCreationForm(target);
	return ((AForm*)ret);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	int	len = 3;
	std::string *formList = new std::string[len +1];

	formList[0] = "PresidentialPardon";
	formList[1] = "RobotomyRequest";
	formList[2] = "ShrubberyCreation";

	for(int i = 0; i < len; i++)
	{
		if(formList[i] == formName)
		{
			AForm* ret = (this->*makeFormFunctions[i])(target);
			delete []formList;
			return (ret);
		}
	}
	delete []formList;
	return (NULL);
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */

Intern		&Intern::operator=(const Intern &origin)
{
	if(this != &origin)
		*this = origin;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Intern const &intern)
{
	stream << /* add here */ std::endl;
	return (stream);
}
