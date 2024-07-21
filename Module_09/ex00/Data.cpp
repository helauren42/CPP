#include "Data.hpp"

Data::Data(std::list<string> file)
{
	list = file;
	string first_line = *list.begin();
	if(first_line != "date,exchange_rate")
			throw (DataFileInvalid(first_line));
	for(std::list<string>::iterator it = list.begin(); it != list.end(); it++)
	{
		if(it == list.begin())
			it++;
		if(this->isValid(*it) == false)
			throw (DataFileInvalid(*it));
		map.insert({fetchYear(*it), fetchRate(*it)});
	}
}

Data::~Data()
{}

bool Data::isValid(string line)
{
	size_t pos_digit_size = 9;
	char pos_digit[9] = {0, 1, 2, 3, 5, 6, 8, 9, 11};
	// int pos_comma = 10;
	// size_t pos_dash_size = 2;
	// char pos_dash[2] = {4, 7};

	cout << "length: " << line.length() << endl;
	cout << "line: " << line << endl;
	if(line.length() != 12)
		return (false);
	for(int i = 0; line[i]; i++)
	{
		if(isdigit(line[i]))
		{
			int dig = 0;
			while(dig != pos_digit_size)
			{
				if(i == pos_digit[dig])
					break ;
				dig++;
			}
			if(dig == pos_digit_size)
			{
				cerr << "digit issue\n";
				return false;
			}
		}
		else if(line[i] == '-')
		{
			if(i != 4 && i != 7)
			{
				cerr << "dash issue\n";
				return false;
			}
		}
		else if(line[i] == ',')
		{
			if(i != 10)
			{
				cerr << "comma issue\n";
				return false;
			}
		}
		else
		{
			cerr << "invalid character\n";
			return false;
		}
	}
	return (true);
}

string Data::fetchYear(string line)
{
	return(line.substr(0, 10));
}

float Data::fetchRate(string line)
{
	size_t pos = line.find(',');
	std::stringstream ss(line.substr(pos +1));
	float num;
	ss >> num;
	return(num);
}

const char * Data::DataFileInvalid::what() const throw()
{
	return NULL;
	// return (message.c_str());
}