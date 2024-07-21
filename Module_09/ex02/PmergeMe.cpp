#include "PmergMe.hpp"

PmergeMe::PmergeMe()
{};

PmergeMe::PmergeMe(char **av)
{
	std::vector<std::string> strings = this->convertArgs(av);
	this->size = this->arr.size();
	if(this->size % 2 != 0)
		this->size--;
	this->size--;
	this->fordJohnsonSort(this->arr, 0, 1);
};

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
	std::stringstream	ss_int("");
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
			ss_int.str("");
			ss_int.clear();
			ss_int.str(string);
			int	num;
			ss_int >> num;
			this->arr.push_back(num);
			this->deck.push_back(num);
			ss.str("");
			ss.clear();
			ss << av[i];
			string.clear();
			ss >> string;
		}
	}
	return (vec);
}

template <typename Con>
void	PmergeMe::sortPairs(Con& container, int left, int right)
{
	if (arr[i] > arr[i + 1])
		std::swap(arr[i], arr[i + 1]);
	if(right == this->size)
		return ;
	sortPairs(container, ++left, ++right);
}

template <typename Con>
void	PmergeMe::fordJohnsonSort(Con& container, int left, int right)
{
	sortPairs(container, 0, 1);
	
}
