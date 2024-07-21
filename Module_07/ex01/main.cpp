/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:33:32 by helauren          #+#    #+#             */
/*   Updated: 2024/07/21 14:06:03 by helauren         ###   ########.fr       */
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
void	output(T arr)
{
	std::cout << arr << "\n";
}

template<typename T>
void	incrOutput(T arr)
{
	arr += 1;
	std::cout << arr << "\n";
}

int	main(void)
{
	int arrInt[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	iter(arrInt, 10, output);
	iter(arrInt, 10, incrOutput);
	iter(arrInt, 10, init97);
	iter(arrInt, 10, output);

	std::string arrString[4] = {"abc", "dfg", "hij", "klm"};

	iter(arrString, 4, output);
	iter(arrString, 4, init97);
	iter(arrString, 4, output);
}
