/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:08:50 by helauren          #+#    #+#             */
/*   Updated: 2024/05/14 17:46:12 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class	Data
{
	public:
		/* --------- CONSTRUCTORS & DECONSTRUCORS ---------- */
		Data();
		Data(int fill, std::string thhis);
		~Data();
		Data(const Data &data);
		Data	&operator=(const Data &);

		// getters
		int			getFill() const;
		std::string	getThis() const;
		
	private:
		int			_fill;
		std::string _this;
};

std::ostream	&operator<<(std::ostream &stream, const Data &data);

#endif // Data_HPP
