#include "PhoneBook.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::set_contact(Contact *contacts, std::string value, std::string type)
{
	if(value.length() > 10 && (type == "firstName" || type == "lastName" || type == "nickName"))
	{
		value.resize(9);
		value.push_back('.');
	}
	if(type == "firstName")
		contacts->firstName = value;
	else if(type == "lastName")
		contacts->lastName = value;
	else if(type == "nickName")
		contacts->nickName = value;
	else if(type == "phoneNumber")
		contacts->phoneNumber = value;
	else if(type == "darkestSecret")
		contacts->darkestSecret = value;
}

void	Contact::output_names(Contact *contact)
{
	int	i = 0;
	int	j;
	std::string value;

	while (i < 3)
	{
		if (i == 0)
			value = contact->firstName;
		if (i == 1)
			value = contact->lastName;
		if (i == 2)
			value = contact->nickName;
		int	spaces = 10 - value.length();
		j = 0;
		while(j < spaces)
		{
			std::cout << " ";
			j++;
		}
		std::cout << value;
		std::cout << "|";
		i++;
	}
	std::cout << "\n";
}

void	Contact::show_contact_info(Contact* contact)
{
	std::cout << "First Name : " << contact->firstName << "\n";
	std::cout << "LastName : " << contact->lastName << "\n";
	std::cout << "Nickname : " << contact->nickName << "\n";
	std::cout << "Phone number : " << contact->phoneNumber << "\n";
	std::cout << "Darkest secret : " << contact->darkestSecret << "\n";
}
