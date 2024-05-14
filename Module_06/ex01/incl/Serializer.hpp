/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:08:48 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 17:54:51 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "../incl/Data.hpp"

class	Serializer
{
	public:
		static const uintptr_t serialize(const Data* ptr);
		static const Data* deserialize(const uintptr_t addr);
		
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &serializer);
		Serializer	&operator=(const Serializer &);
};

std::ostream	&operator<<(std::ostream &stream, Serializer const &serializer);

#endif // Serializer_HPP
