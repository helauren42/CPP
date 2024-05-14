#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
#include <stdexcept>

class Bureaucrat;

class	AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		AForm();
		AForm(std::string _name, std::string _target, int _sign_grade, int _exec_grade);
		~AForm();
		AForm(const AForm &Aform);

		/* ------------------- METHODS --------------------- */
		virtual void	execute(Bureaucrat const & executor) const = 0;

		/* ------------------- SETTERS --------------------- */
		void				beSigned(Bureaucrat& buro);
		void				setSigned();
		/* ------------------- GETTERS --------------------- */
		
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		std::string			getTarget() const;

		/* ------------------ OVERLOADS -------------------- */
		AForm				&operator=(const AForm &);

		/* ------------------- ERRORS --------------------- */
		void				checkAFormValues();
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
		class FormNotSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};

	private:
		const std::string	name;
		const std::string	target;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;
};

std::ostream	&operator<<(std::ostream &stream, AForm const &Aform);

#endif
