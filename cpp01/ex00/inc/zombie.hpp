#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <string>


class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name) {
        this->name = name;
    }

    void announce() {
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }

    ~Zombie() {
        std::cout << "Destroying zombie: " << name << std::endl;
    }
};

Zombie* newZombie(std::string name) {
    Zombie* zombie = new Zombie(name);
    return zombie;
}

void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}

#endif