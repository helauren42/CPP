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
			std::cout << "default constructor called = " << this << std::endl;
		}
		Array(int n)
		{
			if(n < 0)
				throw indexValueTooLow();
			this->arr = new T [n];
			this->toFree = true;
			this->arrLength = (unsigned int)n;
			std::cout << "int constructor called = " << this << std::endl;
		}
		Array(Array& copy)
		{
			std::cout << "copy constructor called = " << this << std::endl;
			this->arrLength = copy.arrLength;
			this->toFree = true;
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
			std::cout << "tmp arr addr = " << this->arr << std::endl;
			for (unsigned int i = 0; i < rhs.arrLength; i++)
				this->arr[i] = rhs.arr[i];
			return (*this);
		};

		std::out_of_range indexValueTooLow()
		{
			std::out_of_range out("Index value is below 0, when it must be at least 0\n");
			return (out);
		}

		std::out_of_range indexValueTooHigh()
		{
			std::out_of_range out("Index value is above the allocated space\n");
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
			std::cout << "address = " << this << std::endl;
			if(this->toFree == true && this->arr != NULL)
			{
				this->toFree = false;
				std::cout << "addr to free = " << arr << std::endl;
				delete [] this->arr;
				this->arr = NULL;
				std::cout << "it is freed\n\n";
			}
		}
	private:
		bool		toFree;
		unsigned int arrLength;
		T *arr;
};

template<typename T>
std::ostream	&operator<<(std::ostream &stream, const Array<T>& rhs)
{
	stream << &rhs << std::endl;
	return (stream);
}

#endif
