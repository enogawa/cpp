#include <Animals.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
	std::cout << "--------Normal Animal--------\n" << std::endl;
	const Animals *meta = new Animals();
	const Animals *dog = new Dog();
	const Animals *cat = new Cat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound(); // will output the cat sound!
	dog->makeSound();
	meta->makeSound();
	std::cout << "\n--------Wrong Animal--------\n" << std::endl;
	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *cat2 = new WrongCat();
	std::cout << cat->getType() << " " << std::endl;
	cat2->makeSound(); // will output the cat sound!
	meta2->makeSound();
	return 0;
}
