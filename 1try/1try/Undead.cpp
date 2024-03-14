#include <iostream>
#include "Undead.h"
#include "generateRandomDamage.h"

Undead::Undead(int enemyHealth, int playerDamage) : Enemy("Undead", enemyHealth, playerDamage) {}

void Undead::NormalAttack() {
    int damageDealt = generateRandomDamage(10, 20);
    std::cout << "Undead claws at you!" << std::endl;
    std::cout << "Deals " << damageDealt << " damage!" << std::endl;
    damage = damageDealt;
}

void Undead::TauntPlayer() {
    int index = rand() % 2;
    std::cout << "Undead whispers: " << taunts[index] << std::endl;
}

std::string Undead::taunts[2] = { "It's your time to join the Undead army!", "You are already dead" };

