#include <iostream>
#include "Player.h"

Player::Player(const std::string& playerName, int playerHealth, int playerDamage) : name(playerName), health(playerHealth), damage(playerDamage) {}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

void Player::decreaseHealth(int amount) {
    health -= amount;
}

int Player::getDamage() const {
    return damage;
}
