/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 06:33:20 by helauren          #+#    #+#             */
/*   Updated: 2024/02/27 06:46:15 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	iter(T* arr, unsigned int n, void (*f)(T& arg))
{
	for (unsigned int i = 0; i < n; i++)
	{
		f(arr[i]);
	}
}
