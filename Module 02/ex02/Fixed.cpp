/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:59:41 by helauren          #+#    #+#             */
/*   Updated: 2024/02/14 16:41:07 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
: fixed_point_num(0)
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int a)
{
	// std::cout << "Int constructor called\n";
	this->fixed_point_num = (int)(a *(1 << this->fractional_bits));
}

Fixed::Fixed(const float a)
{
	// std::cout << "Float constructor called\n";
	this->fixed_point_num =(int)roundf(a * (float)(1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	float	test;

	// std::cout << "Copy assignment operator called\n";
	test = other.toFloat();
	this->fixed_point_num = test;
	return (*this);
}

bool	Fixed::operator<=(const Fixed& ref)
{
	if (this->fixed_point_num <= ref.fixed_point_num)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& ref)
{
	if (this->fixed_point_num >= ref.fixed_point_num)
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& ref)
{
	if (this->fixed_point_num > ref.fixed_point_num)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& ref)
{
	if (this->fixed_point_num < ref.fixed_point_num)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& ref)
{
	if (this->fixed_point_num != ref.fixed_point_num)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& rhs)
{
	Fixed	total;

	total = (float) this->fixed_point_num / 256 + (float)rhs.fixed_point_num / 256;
	return (total);
}

Fixed	Fixed::operator-(const Fixed& rhs)
{
	Fixed	total;

	total = (float) this->fixed_point_num / 256 - (float)rhs.fixed_point_num / 256;
	return (total);
}

Fixed	Fixed::operator*(const Fixed& rhs)
{
	Fixed	total;

	total = (float) this->fixed_point_num / 256 * (float)rhs.fixed_point_num / 256;
	return (total);
}

Fixed	Fixed::operator/(const Fixed& rhs)
{
	Fixed	total;

	total = this->fixed_point_num / rhs.fixed_point_num;
	return (total);
}

Fixed	Fixed::operator++()
{
	this->fixed_point_num++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->fixed_point_num = this->fixed_point_num +1;
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->fixed_point_num = this->fixed_point_num -1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->fixed_point_num = this->fixed_point_num -1;
	return (temp);
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

Fixed& Fixed::min(Fixed& fixed_point1, Fixed& fixed_point2)
{
	if(fixed_point1.fixed_point_num < fixed_point2.fixed_point_num)
		return(fixed_point1);
	return(fixed_point2);
}

const Fixed&	Fixed::min(const Fixed& fixed_point1, const Fixed& fixed_point2)
{
	if(fixed_point1.fixed_point_num < fixed_point2.fixed_point_num)
		return (fixed_point1);
	return(fixed_point2);
}

Fixed&	Fixed::max(Fixed& fixed_point1, Fixed& fixed_point2)
{
	if(fixed_point1.fixed_point_num > fixed_point2.fixed_point_num)
		return (fixed_point1);
	return(fixed_point2);
}

const Fixed&	Fixed::max(const Fixed& fixed_point1, const Fixed& fixed_point2)
{
	if(fixed_point1.fixed_point_num > fixed_point2.fixed_point_num)
		return (fixed_point1);
	return(fixed_point2);	
}
