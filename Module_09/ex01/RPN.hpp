#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <exception>
#include <sstream>

using	std::cout;
using	std::cerr;
using	std::endl;

enum
{
	NUMBER,
	OPERATOR,
};

struct lexir
{
	std::string	content;
	int			type;
};

class RPN
{
	public:
		RPN();
		RPN(const std::queue<std::string>& s);
		~RPN();
		bool    validOperators(const std::string& s) const;
		bool	isValidContent() const;
		bool	isValidNum(const std::string& s) const;

		void	executeOperations();
		int		compute(int first, int second, char c);

		// EXCEPTIONS
		class	defaultException : public std::exception
		{
			public:
				defaultException(const std::string& s);
				~defaultException();
				const char* what() const throw();
			private:
				std::string	error_message;
		};

		class	logicalErrorException : public std::exception
		{
			public:
				logicalErrorException(const std::string& s);
				~logicalErrorException();
				const char* what() const throw();
			private:
				std::string	error_message;
		};

	private:
		std::queue<std::string>	raw_content;
		std::stack<int>				stack;
};

void	outputQueue(std::queue<std::string> s);
std::queue<std::string> lexirArgs(std::queue<std::string> args);
