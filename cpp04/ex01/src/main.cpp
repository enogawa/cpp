#include <Animals.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q ex01");
}

int main()
{
	{
		const Animals *j = new Dog();
		const Animals *i = new Cat();
		delete j; // should not create a leak
		delete i;

		std::cout << "-----------------------------------------\n";
		Dog *test = new Dog();
		test->makeSound();
		test->Animals::makeSound();
		delete test;
	}
	std::cout << "\n-------------------Dog constructor----------------------\n";
	{
		Animals *test[4];
		test[0] = new Dog();
		test[1] = new Dog();
		std::cout << "\n----------------Cat constructor-------------------------\n";
		test[2] = new Cat();
		test[3] = new Cat();
		std::cout << "\n------------------makeSound-----------------------\n";
		for (size_t i = 0; i < 4; i++)
		{
			test[i]->makeSound();
			delete test[i];
			std::cout << "-----------------------------------------\n";
		}
	}
	return 0;
}
