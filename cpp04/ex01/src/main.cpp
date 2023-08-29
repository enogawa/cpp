#include <Animal.hpp>
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
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;

		std::cout << "-----------------------------------------\n";
		Dog *test = new Dog();
		test->makeSound();
		test->Animal::makeSound();
		delete test;
	}
	std::cout << "\n-------------------Dog constructor----------------------\n";
	{
		Animal *test[4];
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
