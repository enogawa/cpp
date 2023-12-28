#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
# include <exception>
# include <stdexcept>

template	<typename	T>
class Array
{
private:
	T	*_arr;
	unsigned int	_n;
	
public:
	Array() : _arr(0), _n(0)
	{
		std::cout << "Default constructor called" << std::endl;
	}

	Array(unsigned int n) : _arr(new T[n]), _n(n)
	{
		std::cout << "Constructor called" << std::endl;
	}


	Array(const Array &cp) : _arr(new T[cp._n]), _n(cp._n)
	{
		std::cout << "Copy constructor called" << std::endl;
		for (size_t i = 0; i < cp._n; i++)
			this->_arr[i] = cp._arr[i];
	}

	~Array()
	{
		delete [] this->_arr;
		std::cout << "Destructor called" << std::endl;
	}

	unsigned int	size()
	{
		return (this->_n);
	}

	Array	&operator=(const Array &cp)
	{
		std::cout << "Copy assigment operator called" << std::endl;
		if (this != &cp)
		{
			if (this->_n != cp._n)
				throw(outOfRange());
			for (size_t i = 0; i < cp._n; i++)
			{
				std::cout << "debug" << std::endl;
				this->_arr[i] = cp._arr[i];
			}
		}
		return (*this);
	}

	class outOfRange : public std::exception{
		const char* what() const throw()
		{
			return ("[exception] this index is out of range");
		}
	};
	
	T	&operator[](unsigned int n) const
	{
		if (this->_n <= n)
			throw(outOfRange());
		return (this->_arr[n]);
	}

};

#endif