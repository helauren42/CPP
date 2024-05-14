/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helauren <helauren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:04:47 by helauren          #+#    #+#             */
/*   Updated: 2024/02/03 17:16:12 by helauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::incr_n(PhoneBook *pb)
{
	if(contact_len < 8)
		contact_len++;
	pb->n++;
}

void	PhoneBook::init_n(PhoneBook *pb)
{
	pb->n = 0;
}

void	PhoneBook::add_contact(PhoneBook *pb)
{
	std::string	value;
	if(pb->n == 8)
		pb->init_n(pb);
	while(value.length() == 0)
	{
		std::cout << "input the first name: ";
		std::getline(std::cin, value);
		pb->contacts[pb->n].set_contact(&pb->contacts[pb->n], value, "firstName");
	}
	value = "";
	while(value.length() == 0)
	{
		std::cout << "input the last name: ";
		std::getline(std::cin, value);
		pb->contacts[pb->n].set_contact(&pb->contacts[pb->n], value, "lastName");
	}
	value = "";
	while(value.length() == 0)
	{
		std::cout << "input the nickname: ";
		std::getline(std::cin, value);
		pb->contacts[pb->n].set_contact(&pb->contacts[pb->n], value, "nickName");
	}
	value = "";
	while(value.length() == 0)
	{
		std::cout << "input the phone number: ";
		std::getline(std::cin, value);
		pb->contacts[pb->n].set_contact(&pb->contacts[pb->n], value, "phoneNumber");
	}
	value = "";
	while(value.length() == 0)
	{
		std::cout << "input the darkest secret: ";
		std::getline(std::cin, value);
		pb->contacts[pb->n].set_contact(&pb->contacts[pb->n], value, "darkestSecret");
	}
	pb->incr_n(pb);
}

void	PhoneBook::search_contact(PhoneBook *pb)
{
	pb->output_headers();
	int	i = 0;
	while(i < pb->contact_len)
	{
		std::cout << "|         "
				<< i +1;
		std::cout << "|";
		pb->contacts[i].output_names(&pb->contacts[i]);
		pb->output_dotted_row();
		i++;
	}
};

void	PhoneBook::search_specific_contact(PhoneBook *pb, int id)
{
	if(id <= 0 || id > pb->contact_len)
	{
		output_invalid_value();
		return ;
	}
	pb->contacts->show_contact_info(&pb->contacts[id -1]);
};

int	isStringDigits(std::string s)
{
	int	i = 0;
	while(s[i])
	{
		if(isdigit(s[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

std::string cut_space(std::string s)
{
	size_t start;
	size_t end;

	start = s.find_first_not_of(" ");
	end = s.find_last_not_of(" ");
	return (s.substr(start, end - start +1));
}

void	PhoneBook::init_n_and_sign(PhoneBook *pb)
{
	pb->n = 0;
	pb->sign = 0;
	pb->contact_len = 0;
}

int	main(void)
{
	std::string	prompt("$> ");
	std::string	line;
	PhoneBook	pb;

	pb.init_n_and_sign(&pb);
	while(1)
	{
		std::cout << prompt;
		std::getline(std::cin, line);
		if(line == "EXIT"|| std::cin.eof())
			break ;
		if(line.empty())
			continue ;
		line = cut_space(line);
		if(line == "ADD")
			pb.add_contact(&pb);
		else if (line == "SEARCH")
		{
			pb.search_contact(&pb);
			std::cout << "Type the index value of the contact who's mobile number and darkest secret you want to know !!!\nIndex : ";
			std::getline(std::cin, line);
			if(line.length() > 1 || isStringDigits(line) == 1)
				pb.output_invalid_value();
			else
				pb.search_specific_contact(&pb, atoi(line.c_str()));
		}
	}
	return (0);
}
