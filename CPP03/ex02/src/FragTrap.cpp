#include "../headers/FragTrap.hpp"

FragTrap::FragTrap (std::string name) : ClapTrap(name) {
    this->setHP(100);
    this->setMP(100);
    this->setATK(30);
    std::cout << "---FragTrap " << this->getName() << " has been created---\n";
}

FragTrap::FragTrap (const FragTrap& original) : ClapTrap(original) {
    std::cout << "Copy constructor has been called\n";
    setName(original.getName());
    setHP(original.getHP());
    setMP(original.getMP());
    setATK(original.getATK());
}

FragTrap &FragTrap::operator=(const FragTrap& original) {
    std::cout << "Copy assignment operator has been called\n";
    if (this == &original)
        return (*this);
    ClapTrap::operator=(original);
    setName(original.getName());
    setHP(original.getHP());
    setMP(original.getMP());
    setATK(original.getATK());
    return (*this);
}

FragTrap::~FragTrap () {
    if (getHP() > 0)
        std::cout << "\n---FragTrap " << getName() << " was victorious!---\n";
    else std::cout << "\n---FragTrap " << getName() << " has been destroyed---\n";
}

void FragTrap::guardGate() {
    std::cout << "FragTrap " << getName() << " is now in Gate keeper mode\n";
}

void FragTrap::setFragHP(unsigned int amount) {
    setHP(amount);
}

void FragTrap::setFragMP(unsigned int amount) {
    setMP(amount);
}

int FragTrap::getFragHP() {
    return (getHP());
}

int FragTrap::getFragMP() {
    return (getMP());
}

int FragTrap::getFragATK() {
    return (getATK());
}

std::string FragTrap::getFragName() {
    return (getName());
}

void FragTrap::fragAttack(const std::string& target) {
    std::cout << "-------HOL' UP!-------\n\n";
    std::cout << getName() << " IS ATTACKING!\n";
    attack(target);
    std::cout << "\n----------------------\n\n";
}

void FragTrap::fragTakeDmg(unsigned int amount) {
    takeDamage(amount);
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << getName() << " wants a high five!\n";
}
