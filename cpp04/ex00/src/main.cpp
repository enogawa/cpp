#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
	std::cout << "--------Normal Animal--------\n" << std::endl;
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "--------type--------\n" << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << "--------sound--------\n" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound(); // will output the cat sound!
	std::cout << "\n--------Wrong Animal--------\n" << std::endl;
	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *cat2 = new WrongCat();
	std::cout << "--------type--------\n" << std::endl;
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << cat2->getType() << " " << std::endl;
	std::cout << "--------sound--------\n" << std::endl;
	cat2->makeSound(); // will output the cat sound!
	meta2->makeSound();
	return 0;
}
