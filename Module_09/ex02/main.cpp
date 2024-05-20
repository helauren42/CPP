#include "PmergMe.hpp"

using std::cerr;
using std::cout;
using std::endl;




int main(int ac, char **av)
{
	if(ac < 2)
		return (cerr << "Requires a positive integer sequence as arguments", 1);
	PmergeMe	merger;
	std::vector<std::string> strings = merger.convertArgs(&av[1]);
	
}
