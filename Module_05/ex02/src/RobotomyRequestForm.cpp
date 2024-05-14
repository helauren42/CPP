/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:47 by helauren          #+#    #+#             */
/*   Updated: 2024/04/25 16:32:15 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/AForm.hpp"
#include <cstdlib>

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy request", "someone", 72, 45)
{
	this->bruh = 0;
}

RobotomyRequestForm::RobotomyRequestForm(std::string var)
: AForm("Robotomy request", var, 72, 45)
{
	this->bruh = 0;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform)
: AForm(robotomyrequestform)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

/* ----------------------------- METHODS ------------------------------- */

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */

RobotomyRequestForm		&RobotomyRequestForm::operator=(const RobotomyRequestForm &origin)
{
	(void) origin;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, RobotomyRequestForm const &robotomyrequestform)
{
	stream << robotomyrequestform.getName();
	if(robotomyrequestform.getIsSigned() == true)
		stream << " has been signed ";
	else
		stream << " has not been signed ";
	stream << ", sign grade is ";
	stream << robotomyrequestform.getSignGrade();
	stream << ", exec grade is ";
	stream << robotomyrequestform.getExecGrade();
	stream << std::endl;
	return (stream);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	this->bruh++;
	AForm::execute(executor);
	std::cout << "<drilling noise> Drrrrr drrrriiiii drrirrriirrrrir driiiiill";
	if(this->bruh % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << " was target but robotomy failed" << std::endl;
}
