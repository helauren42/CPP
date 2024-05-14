/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookOutputs.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:24:33 by helauren          #+#    #+#             */
/*   Updated: 2024/02/02 17:22:11 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::output_dotted_row(void)
{
	std::cout << "|-------------------------------------------|\n";
}

void	PhoneBook::output_headers(void)
{
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "|-------------------------------------------|\n";
}

void	PhoneBook::output_invalid_value(void)
{
	std::cout << "invalid value, no contact found\n";
}
