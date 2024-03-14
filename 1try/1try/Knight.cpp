#include <iostream>
#include "Knight.h"

#include "generateRandomDamage.h"

Knight::Knight(const std::string& playerName, int playerHealth, int playerDamage) : Player(playerName, playerHealth, playerDamage) {}

void Knight::NormalAttack() {
    int damageDealt = generateRandomDamage(20, 25);
    std::cout << "Knight " << name << " swings a sword!" << std::endl;
    std::cout << "You deal " << damageDealt << " damage!" << std::endl;
    damage = damageDealt;
}

void Knight::SpecialAttack() {
    int damageDealt = generateRandomDamage(30, 35);
    std::cout << "Knight " << name << " performs " << specialAttackName << "!" << std::endl;
    std::cout << "You deal " << damageDealt << " damage!" << std::endl;
    damage = damageDealt;
}
std::string Knight::specialAttackName = "Charge";
