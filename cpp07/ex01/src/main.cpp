#include <iostream>
#include "../inc/iter.hpp"

template <typename T>
void print(T &a)
{
	std::cout << a;
}

int main(void)
{
	int intarr[5] = {0, 1, 2, 3, 4};
	char chararr[3] = {'a', 'b', 'c'};
	std::string strarr[4] = {"42", "to", "kyo", " enogawa"};

	iter(intarr, 5, print<int>);
	std::cout << std::endl;

	iter(chararr, 3, print<char>);
	std::cout << std::endl;

	iter(strarr, 4, print<std::string>);
	std::cout << std::endl;

	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }