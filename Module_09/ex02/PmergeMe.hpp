#pragma once

#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>
#include <ctime>
#include <sstream>
#include <cstddef>
#include <array>
#include <exception>
#include <map>
#include <deque>

using std::endl;
using std::cout;
using std::cerr;
using std::vector;
using std::deque;
using vec_int_it = vector<int>::iterator;
using vec_pair_int = vector<std::pair<int, int>>;
using deque_int_it = deque<int>::iterator;
using deque_pair_int = deque<std::pair<int, int>>;

class PmergeMe
{
	public:
		//Orthodox Canonical Form
		PmergeMe();
		PmergeMe(char **av);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		// METHODS
		void			convertArgs(char **av);
		void			outputContainers() const;

		// VECTOR
		void			sortVector();
		void			sortPairVector();
		vec_pair_int	mergeSortPairVector(vec_pair_int mini_vec);
		void			unPairVector();
		void			JacobsthalInsert();
		void			binarySearchVector(int max_value_y, int x_max);

	private:
		vector<unsigned long> jacobsthal_diff;

		std::deque<int>		deck;

		std::vector<int>	vec;
		std::vector<int>	vecTemp;
		vec_pair_int		vecPair;
};

