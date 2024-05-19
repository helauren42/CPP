#pragma once

#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <algorithm>
#include <deque>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstddef>


class PmergeMe
{
	public:
		//Orthodox Canonical Form
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

	private:
		std::deque<int>	deck;
};
