/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:59:09 by helauren          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:13 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int a);
		Fixed(const float a);
		~Fixed();

		Fixed& operator=(const Fixed& other);

		bool	operator<(const Fixed& ref);
		bool	operator>(const Fixed& ref);
		bool	operator<=(const Fixed& ref);
		bool	operator>=(const Fixed& ref);
		bool	operator!=(const Fixed& ref);

		Fixed	operator+(const Fixed& rhs);
		Fixed	operator*(const Fixed& rhs);
		Fixed	operator-(const Fixed& rhs);
		Fixed	operator/(const Fixed& rhs);

		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		static			Fixed&	min(Fixed& fixed_point1, Fixed& fixed_point2);
		static const	Fixed&	min(const Fixed& fixed_point1, const Fixed& fixed_point2);
		static			Fixed&	max(Fixed& fixed_point1, Fixed& fixed_point2);
		static const	Fixed&	max(const Fixed& fixed_point1, const Fixed& fixed_point2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getFractionalBits(void) const;

	private:
		int					fixed_point_num;
		static const int	fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& type);
