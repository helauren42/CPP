#include "PmergeMe.hpp"
#include <list>



int main(int ac, char **av)
{
	if(ac < 2)
		return (cerr << "Requires a positive integer sequence as arguments, a string of numbers such as \"5465 56\" will only take the first number \"5465\"\n", 1);
	try
	{
		PmergeMe	merger(&av[1]);

		cout << "BEFORE: " << endl;
		merger.outputContainers();
		cout << endl;

		double start_time = std::clock();
		cout << "start time: " << start_time << endl;
		merger.sortVector();
		double end_time = std::clock();
		double elapsed_time1 = end_time - start_time;

		start_time = std::clock();
		cout << "start time: " << start_time << endl;
		merger.sortList();
		end_time = std::clock();

		cout << "AFTER: " << endl;
		merger.outputContainers();
		cout << endl;
		double elapsed_time2 = end_time - start_time;
		cout << "Vector elapsed time: " << elapsed_time1 / CLOCKS_PER_SEC * 1000 << " ms" << endl;
		cout << "List elapsed time: " << elapsed_time2 / CLOCKS_PER_SEC * 1000 << " ms" << endl;
	}
	catch(const char *e) {
		std::cerr << "ERROR: " << e << '\n';
	}
	return (0);	
}
