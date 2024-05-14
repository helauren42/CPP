/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:53 by helauren          #+#    #+#             */
/*   Updated: 2024/05/07 17:34:52 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/AForm.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Shrubbery creation", "ShrubFile", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetFile)
: AForm("Shrubbery creation", targetFile, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform)
: AForm("Shrubbery creation", shrubberycreationform.getTarget(), 145, 137)
{
}

/* ----------------------------- METHODS ------------------------------- */

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origin)
{
	(void) origin;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &shrubberycreationform)
{
	stream << shrubberycreationform.getName();
	if(shrubberycreationform.getIsSigned() == true)
		stream << " has been signed ";
	else
		stream << " has not been signed ";
	stream << ", sign grade is ";
	stream << shrubberycreationform.getSignGrade();
	stream << ", exec grade is ";
	stream << shrubberycreationform.getExecGrade();
	stream << std::endl;
	return (stream);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::ofstream	outFile;
	std::string		name;

	name = this->getTarget() + "_shrubbery";
	outFile.open(name.c_str(), std::fstream::out);
	outFile << "       * " << std::endl;
	outFile << "      ***" << std::endl;
	outFile << "     *****" << std::endl;
	outFile << "    *******" << std::endl;
	outFile << "   *********" << std::endl;
	outFile << "  ***********" << std::endl;
	outFile << " *************" << std::endl;
	outFile << "***************" << std::endl;
	outFile << "      |||" << std::endl;
	outFile << "      |||" << std::endl;
}
