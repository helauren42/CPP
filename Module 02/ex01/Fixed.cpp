/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:59:41 by helauren          #+#    #+#             */
/*   Updated: 2024/02/14 16:10:55 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: fixed_point_num(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int a)
{
	std::cout << "Int constructor called\n";
	this->fixed_point_num = (int)(a *(1 << this->fractional_bits));
}

Fixed::Fixed(const float a)
{
	std::cout << "Float constructor called\n";
	this->fixed_point_num =(int)roundf(a * (float)(1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	float	test;

	std::cout << "Copy assignment operator called\n";
	test = other.toFloat();
	this->fixed_point_num = test;
	return (*this);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& type)
{
	float	num;

	num = type.toFloat();
	num = (float)num / (float)(1 << type.getFractionalBits());
	stream << num;
	return (stream);
}

int	Fixed::toInt(void) const
{
	return ((int)this->fixed_point_num / (float)(1 << this->getFractionalBits()));
}	

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_num);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point_num);
}

int		Fixed::getFractionalBits(void) const
{
	return((int)this->fractional_bits);
}


void Fixed::setRawBits(int const raw)
{
	this->fixed_point_num = (int)raw;
}
