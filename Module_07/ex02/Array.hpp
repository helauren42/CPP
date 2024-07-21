#ifndef ARRAY_HPP
# define ARRAY_HPP 

#include <iostream>
#include <exception>
#include <stdexcept>

template<typename T>
class Array
{
	public:
		// Construction
		Array()
		{
			this->arr = new T [0];
			this->toFree = true;
			this->arrLength = 0;
			// std::cout << "default constructor called = " << this << std::endl;
		}
		Array(unsigned int n)
		{
			this->arr = new T [n];
			this->toFree = true;
			this->arrLength = n;
			std::cout << "Constructor for an Array of size \"" << n << "\" called"  << this << std::endl;
		}
		Array(Array& copy)
		{
			std::cout << "copy constructor called = " << this << std::endl;
			this->arrLength = copy.arrLength;
			this->toFree = copy.toFree;
			this->arr = new T [copy.arrLength];
			for (unsigned int i = 0; i < copy.arrLength; i++)
				this->arr[i] = copy.arr[i];
		}

		// Assignment operators
		Array& operator=(const Array& rhs)
		{
			delete [] this->arr;
			std::cout << "assignment operator called = " << this << std::endl;
			this->arrLength = rhs.arrLength;
			this->toFree = true;
			this->arr = new T [rhs.arrLength];
			for (unsigned int i = 0; i < rhs.arrLength; i++)
				this->arr[i] = rhs.arr[i];
			return (*this);
		};

		std::out_of_range indexValueTooLow()
		{
			std::out_of_range out("ERROR: Index value is below 0, when it must be at least 0\n");
			return (out);
		}

		std::out_of_range indexValueTooHigh()
		{
			std::out_of_range out("ERROR: Index value is above the allocated space\n");
			return (out);
		}

		// overloading subscript operator
		T &operator[](int n)
		{
			if(n < 0)
				throw indexValueTooLow();
			if (n >= static_cast<int>(this->arrLength))
				throw indexValueTooHigh();
			return (this->arr[n]);
		}

		// Destruction
		~Array()
		{
			std::cout << "destructor called\n";
			if(this->toFree == true && this->arr != NULL)
			{
				this->toFree = false;
				delete [] this->arr;
				this->arr = NULL;
			}
		}

		// GETTERS
		unsigned int	getArrayLength() const
		{
			return (this->arrLength);
		}
		
		T	getArrElement(int i) const
		{
			return (this->arr[i]);
		}

	private:
		bool			toFree;
		unsigned int	arrLength;
		T *arr;
};

template<typename T>
std::ostream	&operator<<(std::ostream &stream, const Array<T>& rhs)
{
	for(int i = 0; static_cast<unsigned int>(i) < rhs.getArrayLength(); i++)
	{
		stream << "rhs[" << i << "]: " << rhs.getArrElement(i) << std::endl;
	}
	stream << &rhs << std::endl;
	return (stream);
}

#endif
