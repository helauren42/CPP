/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:52:49 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 20:55:20 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ScalarTypes.hpp"
#include <sstream>
#include <iomanip>

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

ScalarTypes::ScalarTypes()
{ }

ScalarTypes::~ScalarTypes() { }

ScalarTypes::ScalarTypes(const ScalarTypes &scalartypes)
{
	*this = scalartypes;
}

/* ----------------------------- METHODS ------------------------------- */

// bool	isDigit(char c)
// {
// 	if(c >= 48 && c <= 57)
// 		return (true);
// 	return (false);
// }

void	ScalarTypes::convertChar(std::string s)
{
	std::stringstream	ss;

	this->character = s[0];
	ss << s;
	ss >> this->integer;
	this->integer = static_cast<int>(this->character);
	this->floating = static_cast<float>(this->integer);
	this->doublefloat = static_cast<double>(this->integer);
}

void	ScalarTypes::convertFloat(std::string s)
{
	std::stringstream	ss;
	int					temp;

	ss << s;
	ss >> this->floating;
	this->doublefloat = static_cast<double>(this->floating);
	this->integer = static_cast<int>(this->floating);
	if(this->doublefloat < 0 || this->doublefloat > 255)
		this->isValidChar = false;
	this->character = static_cast<char>(this->integer);
}

void	ScalarTypes::convertDouble(std::string s)
{
	std::stringstream	ss;
	double				decimal = 0;
	double					temp = 0;

	ss << s;
	ss >> temp;
	this->doublefloat += temp;
	
	this->floating = static_cast<float>(this->doublefloat);
	this->integer = static_cast<int>(this->doublefloat);
	if(this->doublefloat < 0 || this->doublefloat > 255)
		this->isValidChar = false;
	this->character = static_cast<char>(this->doublefloat);
}

void	ScalarTypes::convertInt(std::string s)
{
	std::stringstream	ss;

	ss << s;
	ss >> this->integer;
	this->floating = static_cast<float>(this->integer);
	this->doublefloat = static_cast<double>(this->integer);
	if(this->doublefloat < 0 || this->doublefloat > 255)
		this->isValidChar = false;
	this->character = static_cast<char>(this->integer);
}


bool	ScalarTypes::isValidInput(std::string s)
{
	this->valid = VALID;
	this->setLenDecimal(0);
	for(int i = 0; s[i]; i++)
	{
		if(s[s.length() -1] == 'f')
			break ;
		if(s.length() != 1 && s[i] != '.' && s[i] != '-' && std::isdigit(s[i]) == false)
			return (false);
	}

	size_t	pos = 0;
	pos = s.find('.');
	if(pos != s.find_first_of('.', pos)) // if more than two dots then error
		return (false);
	pos = s.find_first_of('.');
	if(pos == std::string::npos)
		return (true);
	pos++;
	while(s[pos]) // set decimal length
	{
		if(s[pos] == 'f')
			return (true);
		this->setLenDecimal(this->getLenDecimal() + 1);
		pos++;
	}
	std::cout << "len decimal: " << this->getLenDecimal() << std::endl;
	return (true);
}

void	ScalarTypes::convert(std::string s)
{
	int	type;

	this->valid = VALID;
	this->isValidChar = true;
	this->setType(s);
	type = this->getType();
	std::cout << std::fixed << std::setprecision(12);
	switch (type)
	{
		case numChar:
			this->convertChar(s);
			break;
		case numFloat:
			this->convertFloat(s);
			break;
		case numDouble:
			this->convertDouble(s);
			break;
		case numInt:
			this->convertInt(s);
			break;
	}
	if(this->getLenDecimal() > 6)
		this->setLenDecimal((size_t)6);
}

/* ----------------------------- SETTERS ------------------------------- */

void	ScalarTypes::setUnvalid(std::string s)
{
	if(s == "-inf")
		this->valid = NEGINF;
	else if(s == "+inf")
		this->valid = POSINF;
	else
		this->valid = ERROR;
}

void	ScalarTypes::setLenDecimal(size_t value)
{
	this->lenDecimal = value;
}

void	ScalarTypes::setType(std::string s)
{
	if(s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		this->type = numChar;
	else if(s[s.length() -1] == 'f')
		this->type = numFloat;
	else if(s.find('.') != std::string::npos)
		this->type = numDouble;
	else
		this->type = numInt;
}

/* ----------------------------- GETTERS ------------------------------- */

size_t	ScalarTypes::getLenDecimal() const
{
	return (this->lenDecimal);
}

int	ScalarTypes::getValid() const
{
	return(this->valid);
}

bool	ScalarTypes::getValidChar() const
{
	return(this->isValidChar);
}

char	ScalarTypes::getChar() const
{
	return(this->character);
}

int		ScalarTypes::getInt() const
{
	return(this->integer);
}

float	ScalarTypes::getFloat() const
{
	return(this->floating);
}

double	ScalarTypes::getDouble() const
{
	return(this->doublefloat);
}

int	ScalarTypes::getType() const
{
	return (this->type);
}

/* ---------------------------- OVERLOADS ------------------------------ */

ScalarTypes		&ScalarTypes::operator=(const ScalarTypes &origin)
{
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, ScalarTypes const &scalartypes)
{
	stream << "TYPE: ";

	switch(scalartypes.getType())
	{
		case 0:
			stream << "Char";
			break;
		case 1:
			stream << "Float";
			break;
		case 2:
			stream << "Double";
			break;
		case 3:
			stream << "Int";
			break;
	}
	stream << std::endl;

	stream << std::fixed << std::setprecision(scalartypes.getLenDecimal());
	if(scalartypes.getValid() != VALID)
	{
		stream << "char: " << "impossible" << "\n";
		stream << "int: " << "impossible" << "\n";
		switch (scalartypes.getValid())
		{
			case ERROR:
				stream << "float: " << "nan" << "f" << "\n";
				stream << "double: " << "nan" << "\n";
				break;
			case NEGINF:
				stream << "float: " << "-inf" << "f" << "\n";
				stream << "double: " << "-inf" << "\n";
				break;
			case POSINF:
				stream << "float: " << "+inf" << "f" << "\n";
				stream << "double: " << "+inf" << "\n";
				break;
		}
	}
	else
	{
		if(scalartypes.getValidChar() == false || scalartypes.getChar() < 33 || scalartypes.getChar() > 126)
			stream << "char: this character is non displayable" << "\n";
		else
			stream << "char: " << "'" << scalartypes.getChar() << "'" << "\n";
		stream << "int: " << scalartypes.getInt() << "\n";
		stream << "float: " << scalartypes.getFloat() << "f" << "\n";
		stream << "double: " << scalartypes.getDouble() << "\n";
	}
	return (stream);
}

