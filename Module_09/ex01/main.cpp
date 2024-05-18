#include "RPN.hpp"


std::vector<std::string> lexirArgs(std::vector<std::string> args)
{
	std::vector<std::string>	vec;
	std::stringstream			ss;
	std::string					temp;

	for (std::vector<std::string>::iterator it = args.begin() ; it != args.end(); it++)
	{
		ss.clear();
		ss << *it;
		ss >> temp;
		while(temp.empty() == false)
		{
			vec.push_back(temp);
			temp.erase(0, temp.length());
			ss >> temp;
		}
	}
	return (vec);
}

void	outputStringVector(std::vector<std::string> s)
{
	for(std::vector<std::string>::iterator it = s.begin(); it != s.end(); it++)
	{
		std::cout << *it << endl;
	}
}

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
		std::vector<std::string>	args;
		for(int i = 1; av[i]; i++)
			args.push_back(av[i]);
		RPN	classy(lexirArgs(args));
		classy.isValidContent();
		classy.executeOperations();
	}
	catch(const std::exception& e)
	{
		cerr << "EXCEPTION CAUGHT:\n" << e.what() << '\n';
	}
}