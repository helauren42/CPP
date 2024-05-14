/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:32:50 by helauren          #+#    #+#             */
/*   Updated: 2024/04/01 14:02:05 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat()
: name("Default"), grade(1)
{
	std::cout << "Default constructor\n";
	this->checkGrade();
}

Bureaucrat::Bureaucrat(const std::string& initName, int newGrade)
: name(initName), grade(newGrade)
{
	std::cout << "Custom constructor\n";
	this->checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor\n";
	this->checkGrade();
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	// (void) name;
	// char	result[name.length() + 19];
	// name.append("Grade is too high");
	// name.copy(result, name.length(), 0);
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	// (void) name;
	// char	result[name.length() + 19];
	// name.append("Grade is too low");
	// name.copy(result, name.length(), 0);
	return ("Grade is too low");
}

void	Bureaucrat::increment(int amount)
{
	std::cout << "incremented by " << amount << std::endl;
	this->grade -= amount;
	this->checkGrade();
}

void	Bureaucrat::decrement(int amount)
{
	std::cout << "decremented by " << amount << std::endl;
	this->grade += amount;
	this->checkGrade();
}

void	Bureaucrat::checkGrade()
{
	std::string	name = this->getName();
	std::cout << "Checking grade\n";
	if(this->grade < 1)
		throw GradeTooHighException();
	else if(this->grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::setGrade(int newGrade)
{
	this->checkGrade();
	this->grade = newGrade;
}

int	Bureaucrat::getGrade()
{
	return(this->grade);
}

std::string	Bureaucrat::getName()
{
	return(this->name);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::string assignName;

	this->grade = copy.grade;
	return(*this);
}

std::ostream& operator<<(std::ostream& stream, Bureaucrat& rhs)
{
	std::string	ret;
	std::string	stored;
	std::stringstream ss;

	ret = "Bureaucrat :";
	ret += rhs.getName();
	ret += "\n";
	ret += "Has grade :";
	ss << rhs.getGrade();
	ss >> stored;
	ret += stored.c_str();
	ret += "\n";
	stream << ret;
	return (stream);
}

Bureaucrat::~Bureaucrat()
{
}
