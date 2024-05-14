/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:29:22 by helauren          #+#    #+#             */
/*   Updated: 2024/02/03 19:30:14 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>

void	output_invalid_value(void);
int	isStringDigits(std::string s);

class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	void	init_n_and_sign(PhoneBook *pb);
	void	add_contact(PhoneBook *pb);
	void	search_contact(PhoneBook *pb);
	void	search_specific_contact(PhoneBook *pb, int id);
	void	output_dotted_row(void);
	void	output_headers(void);
	void	output_invalid_value(void);
	private:
		int		n;
		int		contact_len;
		int		sign;
		Contact	contacts[8];
		void	init_n(PhoneBook *pb);
		void	incr_n(PhoneBook *pb);
};
