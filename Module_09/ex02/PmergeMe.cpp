#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{};

PmergeMe::PmergeMe(char **av)
{
	this->convertArgs(av);
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
	*this = other;
};

void	PmergeMe::outputContainers() const {
	cout << "VECTOR: " << endl;
	for(vector<int>::const_iterator it = this->vec.begin(); it != this->vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "LIST: " << endl;
	for(list<int>::const_iterator it = this->lst.begin(); it != this->lst.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void	PmergeMe::convertArgs(char **av)
{
	std::stringstream			ss_int;
	std::string					temp;
	int							num;

	for (int i = 0; av[i]; i++)
	{
		std::stringstream	ss(av[i]);
		ss >> temp;
		while(temp.empty() == false)
		{
			ss_int.str("");
			ss_int.clear();
			if(temp.size() == 0)
				break ;
			for(std::string::iterator it = temp.begin(); it != temp.end(); it++)
				if(std::isdigit(*it) == false) {
					throw ("Found invalid character");
				}
			ss_int << temp;
			if(!(ss_int >> num))
				throw ("an argument is not a number");
			if(num < 0)
				throw ("negative number found");
			vec_int_it dup = std::find(this->vec.begin(), this->vec.end(), num);
			if(dup != this->vec.end())
				throw ("Duplicate found");
			this->vec.push_back(num);
			this->lst.push_back(num);
			temp = "";
		}
	}
	
	if(this->vec.size() <= 1) {
		throw("Not enough numbers");
	}
}
