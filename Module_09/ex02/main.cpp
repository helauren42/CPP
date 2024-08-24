#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if(ac < 2)
		return (cerr << "Requires a positive integer sequence as arguments, a string of numbers such as \"5465 56\" will only take the first number \"5465\"\n", 1);
	try
	{
		PmergeMe	merger(&av[1]);
		// CHECK duplicates
		cout << "Initial State" << endl;
		merger.outputContainers();
		cout << "VECTOR:" << endl;
		double start_time = std::clock();
		merger.sortVector();
		double end_time = std::clock();
		double elapsed_time = end_time - start_time;
		cout << "elapsed time: " << elapsed_time << endl;
		cout << "Final State" << endl;
		merger.outputContainers();
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
	}
	return (0);	
}
