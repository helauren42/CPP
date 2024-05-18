#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const std::vector<std::string>& s)
: raw_content(s)
{}

RPN::~RPN()
{}

// EXCEPTIONS

RPN::defaultException::defaultException(const std::string& s)
:error_message(s)
{}

RPN::defaultException::~defaultException()
{}

const char* RPN::defaultException::what() const throw()
{
	return(this->error_message.c_str());
}

RPN::logicalErrorException::logicalErrorException(const std::string& s)
:error_message("Logical error found in input: " + s)
{}

RPN::logicalErrorException::~logicalErrorException()
{}

const char* RPN::logicalErrorException::what() const throw()
{
	return (this->error_message.c_str());
}

bool    RPN::validOperators(const std::string& s) const
{
	if(s.length() > 1)
		return (false);
	char c = s[0];
	if(c != '+' && c != '-' && c != '/' && c != '*')
		return (false);
	return (true);
}

#include <vector>

template <typename T>
int vectorLength(const std::vector<T>& vec)
{
    int i = 0;
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        ++i;
    return i;
}

bool	RPN::isValidNum(const std::string& s) const
{
	if(s.length() == 1 && std::isdigit(s[0]) == true)
		return (true);
	else if (s.length() == 2 && s[0] == '-' && std::isdigit(s[1]) == true)
		return (true);
	return (false);
}

bool	RPN::isValidContent() const
{
	if(this->raw_content.empty() == true)
		throw (defaultException("No numbers or operators provided"));
	if(vectorLength(this->raw_content) <= 2)
		throw (defaultException("Not enough numbers and operators to compute"));
	for (std::vector<std::string>::const_iterator it = this->raw_content.begin(); it != this->raw_content.end(); it++)
	{
		if(it->length() > 2)
			throw (defaultException("String provided too long: " + *it));
		else
			if(this->isValidNum(*it) == false && this->validOperators(*it) == false)
				throw (defaultException("Error: this is not a number nor an operator " + *it));
	}

	int	operators = 0;
	int	operands = 0;
	int	i = 1;
	for (std::vector<std::string>::const_iterator it = this->raw_content.begin(); it != this->raw_content.end(); it++, i++)
	{
		if(this->isValidNum(*it) == true)
			operands++;
		else
			operators++;
		if(operators >= operands)
			throw (logicalErrorException("verify operators and operands"));
	}
	if(operators != operands -1)
		throw (logicalErrorException("wrong amount of operators and operands"));
	return (true);
}

int	RPN::compute(int first, int second, char c)
{
	int	result = 0;
	if(c == '+')
	{
		result = first + second;
		cout << "+\n";
	}
	if(c == '-')
	{
		result = first - second;
		cout << "-\n";
	}
	if(c == '/')
	{
		result = first / second;
		cout << "/\n";
	}
	if(c == '*')
	{
		result = first * second;
		cout << "*\n";
	}
	cout << "first: " << first << ", second: " << second << ", result: " <<  result << endl;
	return (result);
}


void	RPN::executeOperations()
{
	std::stringstream	ss;
	int					num;

	for (std::vector<std::string>::const_iterator it = this->raw_content.begin(); it != this->raw_content.end(); it++)
	{
		if(this->isValidNum(*it) == true)
		{
			ss.str("");
			ss.clear();
			ss << *it;
			ss >> num;
			this->stack.push_back(num);
		}
		else
		{
			std::vector<int>::iterator stackIt = this->stack.end() -1;
			int	second = *stackIt;
			stackIt--;
			int	first = *stackIt;
			this->stack.pop_back();
			this->stack.pop_back();
			this->stack.push_back(compute(first, second, (*it)[0]));
		}
	}
	cout << "FINAL RESULT IS: " << this->stack[0] << endl; 
}
