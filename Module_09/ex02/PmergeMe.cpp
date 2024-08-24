#include "PmergeMe.hpp"

std::vector<unsigned long> generateJacobsthal(int n) {
	std::vector<unsigned long> sequence(n);
	sequence[0] = 1;
	sequence[1] = 2;
	for (int i = 2; i < n; ++i) {
		sequence[i] = sequence[i - 1] + 2 * sequence[i - 2];
	}
	
	return sequence;
	// return {
	// 	2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846,
	// 	43690, 87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810,
	// 	22369622, 44739242, 89478486, 178956970, 357913942, 715827882, 1431655766,
	// 	2863311530, 5726623062, 11453246122, 22906492246, 45812984490, 91625968982,
	// 	183251937962, 366503875926, 733007751850, 1466015503702, 2932031007402,
	// 	5864062014806, 11728124029610, 23456248059222, 46912496118442, 93824992236886,
	// 	187649984473770, 375299968947542, 750599937895082, 1501199875790165,
	// 	3002399751580331, 6004799503160661, 12009599006321322, 24019198012642644,
	// 	48038396025285288, 96076792050570576, 192153584101141152, 384307168202282304,
	// 	768614336404564608, 1537228672809129216, 3074457345618258432, 6148914691236516864};
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
