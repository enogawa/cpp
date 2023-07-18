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

int main() {
    // スタック上でゾンビを作成
    randomChump("Stack Zombie");

    // ヒープ上でゾンビを作成
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    // ヒープ上のゾンビを破棄
    delete heapZombie;

    return 0;
}
