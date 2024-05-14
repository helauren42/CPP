#include <iostream>
#pragma once

class Contact
{
	public:
	Contact();
	~Contact();
	void	set_contact(Contact *contacts, std::string value, std::string type);
	void	output_names(Contact *contact);
	void	show_contact_info(Contact* contact);
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};
