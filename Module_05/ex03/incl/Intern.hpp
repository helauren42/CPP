#pragma once

#include <iostream>
#include "../incl/AForm.hpp"
#include "../incl/Intern.hpp"

class	Intern
{
	typedef AForm* (Intern::*functions)(std::string target);

	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Intern();
		~Intern();
		Intern(const Intern &intern);

		/* ------------------- METHODS --------------------- */
		AForm*	makeForm(std::string formName, std::string target);
		/* ------------------- SETTERS --------------------- */

		/* ------------------- GETTERS --------------------- */

		/* ------------------ OVERLOADS -------------------- */
		Intern	&operator=(const Intern &);

	private:
		functions	makeFormFunctions[3];
		AForm*		makePresidentialPardon(std::string target);
		AForm*		makeRobotmyRequest(std::string target);
		AForm*		makeShrubberyCreation(std::string target);
};

std::ostream	&operator<<(std::ostream &stream, Intern const &intern);
