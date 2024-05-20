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

class PmergeMe
{
	public:
		//Orthodox Canonical Form
		PmergeMe();
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other);
		PmergeMe(const PmergeMe& other);

		// METHODS
		std::vector<std::string>	convertArgs(char **av);

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
		const static size_t	size;
		std::vector<int> arr;
		std::map<int, int> arr;
};
