/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:30:15 by helauren          #+#    #+#             */
/*   Updated: 2024/04/17 15:05:48 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& initName, int newGrade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& copy);

		void				executeForm(AForm const & form);
		void				setGrade(int newGrade);
		void				checkGrade();
		int					getGrade() const;
		std::string			getName() const;
		void				signAForm(AForm& theAForm) const;
		void				increment(int amount);
		void				decrement(int amount);

		class		GradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

	private:
		const std::string	name;
		int					grade;
};

std::ostream& operator<<(std::ostream& stream, Bureaucrat& rhs);

#endif