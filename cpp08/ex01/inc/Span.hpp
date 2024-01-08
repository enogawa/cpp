#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
	public:
		Span(unsigned int N) : N(N)
		{
			std::cout << "Default constructor called" << std::endl;
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
			unsigned int	span = std::numeric_limits<unsigned int>::max();
			std::vector<int> P = this->V;
			if (this->V.size() < 2)
				throw std::out_of_range("vecotor size is too small !");
			std::sort(P.begin(), P.end());
			for (size_t i = 0; i < P.size() - 1; i++)
				span = std::min(span, static_cast<unsigned int>(std::abs(P[i + 1] - P[i])));
			return (span);
		}
		unsigned int	longestSpan()
		{
			unsigned int	span = std::numeric_limits<unsigned int>::min();
			std::vector<int> P = this->V;
			if (this->V.size() < 2)
				throw std::out_of_range("vecotor size is too small !");
			std::sort(P.begin(), P.end());
			span = std::max(span, static_cast<unsigned int>(P[P.size() - 1] - P[0]));
			return (span);
		}
	private:
		std::vector<int>		V;
		unsigned int			N;
};

#endif