/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:08:40 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 17:55:24 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Serializer.hpp"

/* ------------------- CONSTRUCTORS & DECONSTRUCORS -------------------- */

Serializer::Serializer() { }

Serializer::~Serializer() { }

Serializer::Serializer(const Serializer &serializer)
{
	*this = serializer;
}

/* ----------------------------- METHODS ------------------------------- */

const uintptr_t Serializer::serialize(const Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

const Data* Serializer::deserialize(const uintptr_t addr)
{
	return (reinterpret_cast<Data *>(addr));
}

/* ----------------------------- SETTERS ------------------------------- */

/* ----------------------------- GETTERS ------------------------------- */

/* ---------------------------- OVERLOADS ------------------------------ */

Serializer		&Serializer::operator=(const Serializer &origin)
{
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Serializer const &serializer)
{
	stream << /* add here */ std::endl;
	return (stream);
}
