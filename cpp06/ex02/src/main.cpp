#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void){
	srand(time(NULL));
	int d = rand() % 3;
	if (d  == 0)
	{
		std::cout << "generate A class " << std::endl;
		return (new A());
	}
	else if (d == 1)
	{
		std::cout << "generate B class " << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "generate C class " << std::endl;
		return (new C());
	}
}

void identify(Base *p){
	A *a;
	B *b;
	C *c;

	if ((a = dynamic_cast<A*>(p)))
		std::cout << "This is A class object" << std::endl;
	else if ((b = dynamic_cast<B *>(p)))
		std::cout << "This is B class object" << std::endl;
	else if ((c = dynamic_cast<C *>(p)))
		std::cout << "This is C class object" << std::endl;
}

void identify(Base &p){
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "This is A class object" << std::endl;
		static_cast<void>(a);
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "This is B class object" << std::endl;
		static_cast<void>(b);
	}
	catch (const std::exception &e){}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "This is C class object" << std::endl;
		static_cast<void>(c);
	}
	catch (const std::exception &e){}
}

int main(void)
{
	Base *test1  = generate();
	identify(test1);
	identify(*test1);
	delete test1;
	return 0;
}
