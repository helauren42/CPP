#include <iostream>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <cstring>
#include "Data.hpp"

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

	cout << s;
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
	// for(std::list<string>::iterator it = list.begin(); it != list.end(); it++)
	// {
	// 	cout << *it << endl;
	// }
	return (list);
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

	const size_t buff_size = 50;
	char	buff[buff_size];
	std::string	content;

	while(input_stream.getline(buff, 50, '\n'))
	{
		content += buff;
		// std::memset(buff, 0, buff_size);
		// std::fill(std::begin(buff), std::end(buff), 0);
	}

	std::list<std::string> list = listSplitStrings(content, '\n');

	try
	{
		Data data(list);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
