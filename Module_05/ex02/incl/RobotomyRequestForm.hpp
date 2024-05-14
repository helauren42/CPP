#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class	RobotomyRequestForm : public AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		RobotomyRequestForm();
		RobotomyRequestForm(std::string var);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform);

		/* ------------------- METHODS --------------------- */

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &);

	void	execute(Bureaucrat const& executor) const;

	protected:
	
	private:
		mutable int	bruh;
};

std::ostream	&operator<<(std::ostream &stream, RobotomyRequestForm const &robotomyrequestform);

#endif // RobotomyRequestForm_HPP
