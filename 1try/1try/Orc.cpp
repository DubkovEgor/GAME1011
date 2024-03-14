#include <iostream>
#include "Orc.h"

#include "generateRandomDamage.h"

Orc::Orc(int enemyHealth, int playerDamage) : Enemy("Orc", enemyHealth, playerDamage) {}

void Orc::NormalAttack() {
    int damageDealt = generateRandomDamage(20, 25);
    std::cout << "Orc swings a club!" << std::endl;
    std::cout << "Deals " << damageDealt << " damage!" << std::endl;
    damage = damageDealt;
}

void Orc::TauntPlayer() {
    int index = rand() % 3;
    std::cout << "Orc taunts: " << taunts[index] << std::endl;
}

std:: string Orc::taunts[3] = { "You'll never defeat me!", "I'll crush you!", "You're weak!" };
