#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const std::queue<std::string>& s)
: raw_content(s)
{
}

RPN::~RPN()
{}

// EXCEPTIONS

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
	if(s.length() == 1 && std::isdigit(s[0]) != false)
		return (true);
	else if (s.length() == 2 && s[0] == '-' && std::isdigit(s[1]) != false)
		return (true);
	return (false);
}

bool	RPN::isValidContent() const
{
	std::queue<std::string>	temp1(this->raw_content);
	std::queue<std::string>	temp2(this->raw_content);
	std::string	s;

	if(this->raw_content.empty() == true)
		throw (defaultException("No numbers or operators provided"));
	if(this->raw_content.size() <= 2)
		throw (defaultException("Not enough numbers and operators to compute"));
	while (temp1.empty() == false)
	{
		s = temp1.front();
		if(s.length() > 2)
			throw (defaultException("String provided too long: " + s));
		else {
			if(this->isValidNum(s) == false && this->validOperators(s) == false)
				throw (defaultException("Error: this is not a valid number nor a valid operator " + s));
		}
		temp1.pop();
	}

	int	operators = 0;
	int	operands = 0;
	int	i = 1;
	while (temp2.empty() == false)
	{
		s = temp2.front();
		if(this->isValidNum(s) == true)
			operands++;
		else
			operators++;
		if(operators >= operands)
			throw (logicalErrorException("verify operators and operands"));
		temp2.pop();
	}
	if(operators != operands -1)
		throw (logicalErrorException("wrong amount of operators and operands"));
	return (true);
}

int	RPN::compute(int first, int second, char c)
{
	int	result = 0;
	if(c == '+') {
		result = first + second;
		cout << "+\n";
	}
	if(c == '-') {
		result = first - second;
		cout << "-\n";
	}
	if(c == '/') {
		result = first / second;
		cout << "/\n";
	}
	if(c == '*') {
		result = first * second;
		cout << "*\n";
	}
	return (result);
}

void	RPN::executeOperations()
{
	std::stringstream	ss;
	std::string			s;
	int					num;

	while (this->raw_content.empty() == false)
	{
		s = this->raw_content.front();
		if(this->isValidNum(s) == true) {
			ss.str("");
			ss.clear();
			s = this->raw_content.front();
			ss << s;
			ss >> num;
			this->stack.push(num);
		}
		else {
			int	second = stack.top();
			this->stack.pop();
			int	first = stack.top();
			this->stack.pop();
			this->stack.push(compute(first, second, (s)[0]));
		}
		this->raw_content.pop();
	}
}
