/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:31:11 by helauren          #+#    #+#             */
/*   Updated: 2024/05/15 14:18:40 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
# include <algorithm>
#include <exception>
#include <stdexcept>

std::out_of_range notFound()
{
	std::out_of_range ret("Not found in container\n");
	return (ret);
}

template <typename T>
int	easyfind(T &container, int second)
{
	int pos = 0;
	for (typename T::iterator it = container.begin(); it != container.end(); it++, pos++)
		if(*it == second)
			return (pos);
	return (-1);
}

// template<typename T>
// typename T::iterator easyfind(T& container, int needle) {
// 	typename T::iterator it = std::find(container.begin(), container.end(), needle);
// 	return it; // it will be container.end() if needle can't be found
// }
