/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 02:31:11 by helauren          #+#    #+#             */
/*   Updated: 2024/03/05 17:38:52 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
# include <algorithm>
#include <exception>
#include <stdexcept>

// template <typename T>
// typename	T::iterator easyfind(T &container, int second)
// {
// 	std::runtime_error	emptycontainer("Could not iterate through container\n");
// 	for (typename T::iterator it = container.begin(); it != container.end(); it++)
// 		if(*it == second)
// 			return (it);
// 	return (it);
// }

std::out_of_range notFound()
{
	std::out_of_range ret("Not found in container\n");
	return (ret);
}

// template<typename T>
// typename T::iterator easyfind(T& container, int needle) {
// 	typename T::iterator it = std::find(container.begin(), container.end(), needle);
// 	return it; // it will be container.end() if needle can't be found
// }
