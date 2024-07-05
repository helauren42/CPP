#include "RPN.hpp"


std::queue<std::string> lexirArgs(std::queue<std::string> args)
{
	std::queue<std::string>		vec;
	std::stringstream			ss;
	std::string					temp;

	while (args.empty() == false)
	{
		ss.clear();
		ss << args.front();
		ss >> temp;
		while(temp.empty() == false)
		{
			vec.push(temp);
			temp.erase(0, temp.length());
			ss >> temp;
		}
		args.pop();
	}
	return (vec);
}

void	outputQueue(std::queue<std::string> s)
{
	while(s.empty() == false)
	{
		std::cout << s.front() << endl;
		s.pop();
	}
}

// void	outputStringVector(std::vector<std::string> s)
// {
// 	for(std::vector<std::string>::iterator it = s.begin(); it != s.end(); it++)
// 	{
// 		std::cout << *it << endl;
// 	}
// }

int main(int ac, char **av)
{
	if(ac < 2)
	{
		cerr << "You need to pass to pass a Polish Mathematical Expression as argument" << endl;
		cerr << "EX: ./RPN 5 8 + 4 *" << endl;
		return (1);
	}
	try
	{
		std::queue<std::string>	args;
		for(int i = 1; av[i]; i++)
			args.push(av[i]);
		RPN	classy(lexirArgs(args));
		classy.isValidContent();
		classy.executeOperations();
	}
	catch(const std::exception& e)
	{
		cerr << "EXCEPTION CAUGHT:\n" << e.what() << '\n';
	}
}