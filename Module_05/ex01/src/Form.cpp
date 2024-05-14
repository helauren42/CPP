/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 01:35:04 by helauren          #+#    #+#             */
/*   Updated: 2024/04/17 13:43:08 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Form.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Form::Form() 
: name("Default Form"), is_signed(false), sign_grade(55), exec_grade(5)
{}

Form::Form(std::string _name, int _sign_grade, int _exec_grade)
: name(_name), is_signed(false), sign_grade(_sign_grade), exec_grade(_exec_grade)
{}

Form::Form(const Form &form)
: name(form.name), is_signed(form.is_signed), sign_grade(form.sign_grade), exec_grade(form.exec_grade)
{
	this->checkFormValues();
}

Form::~Form() {}

/* ----------------------------- SETTERS ------------------------------- */

void	Form::checkFormValues()
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

void	Form::besigned(Bureaucrat& buro)
{
	std::cout << "Besigned called\n";
	if(buro.getGrade() <= this->getSignGrade())
		this->is_signed = true;
	else
		throw GradeTooLowException();
}

/* ----------------------------- GETTERS ------------------------------- */

std::string	Form::getName() const
{
	return (this->name);
}

bool	Form::getIsSigned() const
{
	return (this->is_signed);
}

int		Form::getExecGrade() const
{
	return (this->exec_grade);
}

int		Form::getSignGrade() const
{
	return (this->sign_grade);
}

/* ---------------------------- OVERLOADS ------------------------------ */

Form	&Form::operator=(const Form &origin)
{
	(void) origin;
	return (*this);
}

/* ---------------------------- EXCEPTIONS ------------------------------ */

const char*	Form::GradeTooHighException::what() const throw ()
{
	return("Form has grade too high < 1");
}

const char*	Form::GradeTooLowException::what() const throw ()
{
	return("Form has grade too low > 150");
}

std::ostream	&operator<<(std::ostream &stream, Form const &form)
{
	stream << std::endl;
	stream << form.getName() << ": ";
	// stream << "Sign grade : " << form.getSignGrade() << std::endl;
	// stream << "Exec grade : " << form.getExecGrade() << std::endl;
	if(form.getIsSigned() == true)
		stream << "WOUHOU it has been signed !\n";
	else
		stream << "OMG it has not been signed !\n";
	return (stream);
}
