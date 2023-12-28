#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
	public:
		Span(unsigned int N) : N(N)
		{
			std::cout << "Defoult constructor called" << std::endl;
		}
		~Span()
		{
			std::cout << "Destructor called" << std::endl;
		}
		void		addNumber(int num)
		{
			if (this->N < V.size())
				throw std::out_of_range("out of range!");
			this->V.push_back(num);
		}
		unsigned int	shortestSpan()
		{
			
		}
		unsigned int	longestSpan()
		{

		}
	private:
		std::vector<int>		V;
		unsigned int			N;
};

#endif