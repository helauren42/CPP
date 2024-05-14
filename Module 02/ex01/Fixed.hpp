/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:59:09 by helauren          #+#    #+#             */
/*   Updated: 2024/02/08 06:27:32 by helauren         ###   ########.fr       */
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
