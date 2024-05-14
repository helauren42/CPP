/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:08:45 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 18:00:58 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Data.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Data::Data()
:_fill(5), _this("weroew")
{}

Data::Data(int fill, std::string thhis)
{
	this->_fill = fill;
	this->_this = thhis;
}

Data::~Data() { }

Data::Data(const Data &data)
{
	*this = data;
}

/* ----------------------------- METHODS ------------------------------- */


/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

int	Data::getFill() const
{
	return this->_fill;
}
std::string	Data::getThis() const
{
	return this->_this;
}

/* ---------------------------- OVERLOADS ------------------------------ */


Data		&Data::operator=(const Data &origin)
{
	*this = origin;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Data &data)
{
	stream << "Data output:\n";
	stream << "Fill is: " << data.getFill() << " this is: " << data.getThis() << std::endl;
	return (stream);
}

