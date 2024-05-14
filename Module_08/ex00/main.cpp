/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:09:38 by helauren          #+#    #+#             */
/*   Updated: 2024/03/05 13:46:26 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main()
{
	std::vector<int> vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	for (int i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << std::endl;
	return (0);
}

// int	main()
// {
// 	int	arr[10];

// 	for (int i = 0; i < 10; i++)
// 		arr[i] = i * i;
// 	std::cout << "Find 64 = " << easyfind(arr, 64) << std::endl;
// 	std::cout << "Find 1 = " << easyfind(arr, 1) << std::endl;
// 	return (0);
// 	// std::vector<int> v;
// }

// int main()
// {
// 	std::vector<int> v;
// 	std::vector<int>::iterator it;

// 	for (int i = 0; i < 10; ++i) {
// 		v.push_back(i * i);
// 	}
// 	std::cout << "Vector:" << std::endl;
// 	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
// 		std::cout << *i << std::endl;
// 	}
// 	std::cout << std::endl;

// 	it = easyfind(v, -3);
// 	if (it == v.end())
// 		std::cout << "Not found" << std::endl;
// 	else
// 		std::cout << "iterator: " << *it << std::endl;

// 	it = easyfind(v, 2);
// 	if (it == v.end()) std::cout << "Not found" << std::endl;
// 	else std::cout << "iterator: " << *it << std::endl;

// 	it = easyfind(v, 25);
// 	if (it == v.end()) std::cout << "Not found" << std::endl;
// 	else std::cout << "iterator: " << *it << std::endl;

// 	it = easyfind(v, 81);
// 	if (it == v.end()) std::cout << "Not found" << std::endl;
// 	else std::cout << "iterator: " << *it << std::endl;
// 	return 0;
// }
