#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		: std::stack<T>()
		{};
		MutantStack(MutantStack& cpy)
		: std::stack<T>()
		{
			*this = cpy;
			return(*this)
		}
		~MutantStack()
		{};
		MutantStack	&operator=(MutantStack& rhs)
		{
			*this = rhs;
			return (*this);
		}
		typedef typename std::stack<t>::container_type::iterator iterator;
		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}
};

#endif