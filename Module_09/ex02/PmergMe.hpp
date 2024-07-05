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
#include <array>
#include <exception>
#include <map>
#include <deque>

class PmergeMe
{
	public:
		//Orthodox Canonical Form
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		PmergeMe(char **av);

		// METHODS
		std::vector<std::string>	convertArgs(char **av);
		template <typename Con>
		void	sortPairs(Con& container, int left, int right);
		template <typename Con>
		void	fordJohnsonSort(Con& container, int left, int right);

		//EXCEPTION
		class defaultException : public std::exception
		{
			public:
				defaultException()
				{};
				defaultException(const std::string& s)
				: error_message(s)
				{};
				~defaultException()
				{};
				const char *what() const throw()
				{
					return (this->error_message.c_str());
				}
			private:
				std::string error_message;
		};

	private:
		int					size;
		std::vector<int>	arr;
		std::deque<int>		deck;
};	

