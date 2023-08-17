#include "../inc/ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("村人");

    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.beRepaired(10);
    claptrap.beRepaired(10);
    claptrap.takeDamage(110000);
    claptrap.attack("リュカ");
    claptrap.attack("リュカ");
    claptrap.beRepaired(10);
    claptrap.beRepaired(10);

    return 0;
}