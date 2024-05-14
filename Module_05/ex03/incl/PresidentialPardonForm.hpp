#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class	PresidentialPardonForm : public AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		PresidentialPardonForm();
		PresidentialPardonForm(std::string var);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform);

		/* ------------------- METHODS --------------------- */

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &);

		void	execute(Bureaucrat const& executor) const;

	protected:
	
	private:

};

std::ostream	&operator<<(std::ostream &stream, PresidentialPardonForm const &presidentialpardonform);

#endif // PresidentialPardonForm_HPP
