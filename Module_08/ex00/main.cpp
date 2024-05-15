/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:38 by helauren          #+#    #+#             */
/*   Updated: 2024/05/15 14:20:15 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

// int	main()
// {
// 	std::vector<int> vec;

// 	for (int i = 0; i < 10; i++)
// 		vec.push_back(i);
// 	for (int i = 0; i < vec.size(); i++)
// 		std::cout << vec.at(i) << std::endl;
// 	return (0);
// }

int	main()
{
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i * i);
		std::cout << "v[" << i << "]: " << v[i] << std::endl;
	}
	std::cout << "Find 64 = " << easyfind(v, 64) << std::endl;
	std::cout << "Find 1 = " << easyfind(v, 1) << std::endl;
	return (0);
}
