#include "MutanStack.hpp"

int main(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top number: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	MutantStack<int>::stack::container_type::iterator it = mstack.begin();
	MutantStack<int>::stack::container_type::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
