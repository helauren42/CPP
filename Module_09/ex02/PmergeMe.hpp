#pragma once

#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
#include <sstream>
#include <cstddef>
#include <array>
#include <exception>
#include <map>
#include <algorithm>

using std::endl;
using std::cout;
using std::cerr;
using std::vector;
using std::list;
using vec_int_it = vector<int>::iterator;
using lst_int_it = list<int>::iterator;

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
		void		sortVector();
		vector<int>	mergeInsertSortVector(vector<int> left, vector<int> right);
		vector<int>	mergeVector(vector<int> left, vector<int> right);

		void		sortList();
		list<int>	mergeInsertSortList(list<int> left, list<int> right);
		list<int>	mergeList(list<int> left, list<int> right);
		list<int>	firstHalf(list<int> _lst);
		list<int>	secondHalf(list<int> _lst);

	private:
		std::list<int>		lst;

		std::vector<int>	vec;
		std::vector<int>	vecTemp;
};

