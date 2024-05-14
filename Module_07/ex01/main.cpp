/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:33:32 by helauren          #+#    #+#             */
/*   Updated: 2024/02/27 20:42:47 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void	init97(T& arr)
{
	arr = 97;
}

template<typename T>
void	ouput(T arr)
{
	std::cout << arr << "\n";
}

int	main(void)
{
	int arrInt[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string arrString[4] = {"abc", "dfg", "hij", "klm"};

	iter(arrInt, 10, ouput);
	iter(arrInt, 10, init97);
	iter(arrInt, 10, ouput);

	iter(arrString, 4, ouput);
	iter(arrString, 4, init97);
	iter(arrString, 4, ouput);
}

// int	main(void)
// {
// 	char a = 0;
// 	std::cout << "a = " << a << "\n";
// }