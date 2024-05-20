#include "PmergMe.hpp"

PmergeMe::PmergeMe(){};

PmergeMe::~PmergeMe(){};

PmergeMe& PmergeMe::operator=(const PmergeMe& other) 
{
	if (this == &other)
		return *this;
	return *this;
};

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)(other);
};

std::vector<std::string>	PmergeMe::convertArgs(char **av)
{
	std::stringstream	ss("");
	std::vector<std::string>	vec;
	std::string			string;
	int					num;

	for (int i = 0; av[i]; i++)
	{
		ss.str("");
		ss.clear();
		ss << av[i];
		string.clear();
		ss >> string;
		while(string.empty() == false)
		{
			for(std::string::iterator it = string.begin(); it != string.end(); it++)
				if(std::isdigit(*it) == false)
					throw (defaultException("Found none digit character: " + *it));
			vec.push_back(string);
			ss.str("");
			ss.clear();
			ss << av[i];
			string.clear();
			ss >> string;
		}
	}
	return (vec);
}
