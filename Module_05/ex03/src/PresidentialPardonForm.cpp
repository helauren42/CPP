/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:50 by helauren          #+#    #+#             */
/*   Updated: 2024/04/17 14:57:18 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/AForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential pardon", "useless form", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string var)
: AForm("Presidential pardon", var, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform)
: AForm(presidentialpardonform)
{
}

/* ----------------------------- METHODS ------------------------------- */

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */

PresidentialPardonForm		&PresidentialPardonForm::operator=(const PresidentialPardonForm &origin)
{
	(void) origin;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, PresidentialPardonForm const &presidentialpardonform)
{
	stream << presidentialpardonform.getName();
	if(presidentialpardonform.getIsSigned() == true)
		stream << " has been signed ";
	else
		stream << " has not been signed ";
	stream << ", sign grade is ";
	stream << presidentialpardonform.getSignGrade();
	stream << ", exec grade is ";
	stream << presidentialpardonform.getExecGrade();
	stream << std::endl;
	return (stream);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
