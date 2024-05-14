#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class Bureaucrat;

class	Form
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Form();
		Form(std::string _name, int _sign_grade, int _exec_grade);
		~Form();
		Form(const Form &form);

		/* ------------------- METHODS --------------------- */

		/* ------------------- SETTERS --------------------- */
		void			besigned(Bureaucrat& buro);
		/* ------------------- GETTERS --------------------- */
		
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		/* ------------------ OVERLOADS -------------------- */
		Form	&operator=(const Form &);

		/* ------------------- ERRORS --------------------- */
		void			checkFormValues();
		class	GradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;
};

std::ostream	&operator<<(std::ostream &stream, Form const &form);

#endif
