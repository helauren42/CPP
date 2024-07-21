#include <iostream>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>

void	trimSpaces(std::string& s)
{
	while(s.length() && std::isspace(s[0]))
		s.erase(s.begin());
	while(s.length() && std::isspace(s[s.length() -1]))
		s = s.substr(0, s.length() -1);
}

std::list<std::string> listSplitStrings(const std::string& s, const char delim)
{
	std::stringstream ss;
	std::string	test;
	std::list<std::string>	list;

	ss << s;
	test = ss.str();
	while(1)
	{
		std::getline(ss, test, delim);
		trimSpaces(test);
		if(test.length() == 0)
			continue;
		list.push_back(test);
		if(ss.eof())
			break ;
	}
	return (list);
}

void	outputData(std::list<std::string> data)
{
	for(std::list<std::string>::iterator it = data.begin(); it != data.end(); it++)
	{
		std::cout << it->
	}
}

bool	validData(std::list<std::string> data)
{
	for(std::list<std::string>::iterator it = data.begin(); it != data.end(); it++)
	{
		
	}
}

int	main(int ac, char **av, char **env)
{
	if(ac != 2)
	{
		std::cerr << "Program must take a file as argument\n";
		return (1);
	}

	std::ifstream	input_stream;
	input_stream.open(av[1]);

	if(input_stream.is_open() == false)
	{
		std::cerr << "File failed to open\n";
		return (1);
	};

	char	buff[80000];

	input_stream.getline(buff, 80000, '\0');
	std::string	s = buff;
	std::list<std::string> data = listSplitStrings(s, '\n');
	if(validData(data) == false)
	{
		std::cerr << "Content in the file is invalid\n";
		return (1);
	};
	outputData(data);
	return (0);
}
