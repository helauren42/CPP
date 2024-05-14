/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:35:04 by helauren          #+#    #+#             */
/*   Updated: 2024/04/17 15:03:44 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

AForm::AForm() 
: name("Default AForm"), target("no target"), is_signed(false), sign_grade(55), exec_grade(5)
{}

AForm::AForm(std::string _name, std::string _target, int _sign_grade, int _exec_grade)
: name(_name), target(_target), is_signed(false), sign_grade(_sign_grade), exec_grade(_exec_grade)
{}

AForm::AForm(const AForm &Aform)
: name(Aform.name), is_signed(Aform.is_signed), sign_grade(Aform.sign_grade), exec_grade(Aform.exec_grade)
{
	this->checkAFormValues();
}

AForm::~AForm() {}

/* ----------------------------- METHODS ------------------------------- */

void	AForm::checkAFormValues()
{
	if(this->sign_grade < 1)
		throw GradeTooHighException();
	else if(this->sign_grade > 150)
		throw GradeTooLowException();
	if(this->exec_grade < 1)
		throw GradeTooHighException();
	else if(this->exec_grade > 150)
		throw GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat& buro)
{
	if(buro.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	if(this->getIsSigned() == true)
		std::cout << this->getTarget() << " is already signed, " << buro.getName() << " did not overwrite the signature\n";
	else
	{
		this->is_signed = true;
		std::cout << buro.getName() << " has signed " << this->getTarget() << "\n";
	}
}

void	AForm::setSigned()
{
	this->is_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if((executor.getGrade() <= this->getExecGrade()) && this->getIsSigned() == true)
	{
		std::cout << executor.getName() << " is executing " << this->getName() << std::endl;
	}
	else
	{
		throw (FormNotSignedException());
	}
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->is_signed);
}

int		AForm::getExecGrade() const
{
	return (this->exec_grade);
}

int		AForm::getSignGrade() const
{
	return (this->sign_grade);
}

std::string	AForm::getTarget() const
{
	return(this->target);
}

/* ---------------------------- OVERLOADS ------------------------------ */

AForm	&AForm::operator=(const AForm &origin)
{
	(void) origin;
	return (*this);
}

/* ---------------------------- EXCEPTIONS ------------------------------ */

const char*	AForm::FormNotSignedException::what() const throw ()
{
	return("Form not signed exception");
}

const char*	AForm::GradeTooHighException::what() const throw ()
{
	return("Form has grade too high < 1");
}

const char*	AForm::GradeTooLowException::what() const throw ()
{
	return("Form has grade too low > 150");
}

std::ostream	&operator<<(std::ostream &stream, AForm const &Aform)
{
	stream << std::endl;
	stream << Aform.getName() << std::endl;
	stream << "Sign grade : " << Aform.getSignGrade() << std::endl;
	stream << "Exec grade : " << Aform.getExecGrade() << std::endl;
	if(Aform.getIsSigned() == true)
		stream << "WOUHOU it has been signed !\n";
	else
		stream << "OMG it has not been signed !\n";
	return (stream);
}
