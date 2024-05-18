#pragma once
#include <iostream>
#include <vector>
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
		RPN(const std::vector<std::string>& s);
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
		std::vector<std::string>	raw_content;
		std::vector<int>			stack;
};

void	outputStringVector(std::vector<std::string> s);
std::vector<std::string> lexirArgs(std::vector<std::string> args);
