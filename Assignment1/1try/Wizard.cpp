#include <iostream>
#include "Wizard.h"

#include "generateRandomDamage.h"

Wizard::Wizard(const std::string& playerName, int playerHealth, int playerDamage) : Player(playerName, playerHealth, playerDamage) {}

void Wizard::NormalAttack() {
    int damageDealt = generateRandomDamage(10, 15);
    std::cout << "Wizard " << name << " casts a normal spell!" << std::endl;
    std::cout << "You deal " << damageDealt << " damage!" << std::endl;
    damage = damageDealt;
}

void Wizard::SpecialAttack() {
    int damageDealt = generateRandomDamage(30, 40);
    std::cout << "Wizard " << name << " casts " << specialAttackName << "!" << std::endl;
    std::cout << "You deal " << damageDealt << " damage!" << std::endl;
    damage = damageDealt;
}
std::string Wizard::specialAttackName = "Fireball";
