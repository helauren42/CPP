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