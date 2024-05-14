/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 00:03:57 by helauren          #+#    #+#             */
/*   Updated: 2024/02/14 16:14:32 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}
	// MY TESTS
	{
		std::cout << "\nMY TESTS:\n" << std::endl;
	
		Fixed a(4);
		Fixed const b(2);
	
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	
		std::cout << "a++: " << a++ << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "++a: " << ++a << std::endl;
		std::cout << "a: " << a << std::endl;
	
		std::cout << "a + b: " << a + b << std::endl;
		// std::cout << "b + a: " << b + a << std::endl;
	
		std::cout << "a - b: " << a - b << std::endl;
		// std::cout << "b - a: " << b - a << std::endl;
	
		std::cout << "a * b: " << a * b << std::endl;
		// std::cout << "b * a: " << b * a << std::endl;
	
		std::cout << "a / b: " << a / b << std::endl;
		// std::cout << "b / a: " << b / a << std::endl;
	
		std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
		std::cout << "max(b, a): " << Fixed::max(a, b) << std::endl;
	
		std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
		std::cout << "min(b, a): " << Fixed::min(a, b) << std::endl;
	
		return 0;
	}
}

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	// std::cout << "step1\n";
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }
