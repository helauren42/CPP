#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class	AForm;

class	ShrubberyCreationForm : public AForm
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string targetFile);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform);
		~ShrubberyCreationForm();

		/* ------------------- METHODS --------------------- */

		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);

		void	execute(Bureaucrat const& executor) const;
	protected:
	
	private:
};

std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &shrubberycreationform);

#endif // ShrubberyCreationForm_HPP


