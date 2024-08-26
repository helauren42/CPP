#include "PmergeMe.hpp"

std::vector<unsigned long> generateJacobsthal(int n) {
	std::vector<unsigned long> sequence(n);
	sequence[0] = 0;
	sequence[1] = 1;
	for (int i = 2; i < n; ++i) {
		sequence[i] = sequence[i - 1] + 2 * sequence[i - 2];
	}
	return sequence;
}

PmergeMe::PmergeMe()
{};

PmergeMe::PmergeMe(char **av)
{
	this->convertArgs(av);
	this->jacobsthal_diff = generateJacobsthal(this->vec.size());
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

void	PmergeMe::outputContainers() const {
	cout << "vector output: " << endl;
	for(vector<int>::const_iterator it = this->vec.begin(); it != this->vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "deque output: " << endl;
	for(deque<int>::const_iterator it = this->deck.begin(); it != this->deck.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void	PmergeMe::convertArgs(char **av)
{
	std::vector<std::string>	vec;
	std::stringstream	ss_int;
	std::string			temp;
	int					num;

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
				if(std::isdigit(*it) == false)
					throw ("Found none digit character: " + *it);
			ss_int << temp;
			if(!(ss_int >> num))
				throw ("an argument is not a number");
			if(num < 0)
				throw ("negative number found");
			this->vec.push_back(num);
			this->deck.push_back(num);
			temp = "";
		}
	}
	if(this->vec.size() <= 1) {
		throw("Not enough numbers");
	}
}
