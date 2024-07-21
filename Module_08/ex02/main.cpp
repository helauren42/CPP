#include "MutanStack.hpp"
#include "vector"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
	
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	std::cout << "Forward way:" << std::endl;

// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}

// 	// std::cout << "Reverse way:" << std::endl;
// 	// MutantStack<int>::reverse_iterator rit = mstack.rbegin();
// 	// MutantStack<int>::reverse_iterator rite = mstack.rend();
// 	// while (rit != rite)
// 	// {
// 	// std::cout << *rit << std::endl;
// 	// ++rit;
// 	// }
// 	return 0;
// }

int main(void)
{
	MutantStack<int> m_stack;

	m_stack.push(42);
	m_stack.push(5);

	std::cout << "Stack size: " << m_stack.size() << std::endl;
	std::cout << "Top number: " << m_stack.top() << std::endl;

	m_stack.pop();

	std::cout << "Post pop Stack size: " << m_stack.size() << std::endl;

	m_stack.push(0);
	m_stack.push(-456);
	m_stack.push(-357);
	m_stack.push(1616);

	std::cout << "Top number: " << m_stack.top() << std::endl;
	std::cout << "Stack size: " << m_stack.size() << std::endl;

	MutantStack<int>::iterator it = m_stack.begin();
	MutantStack<int>::iterator ite = m_stack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}
