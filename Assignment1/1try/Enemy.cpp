#include <iostream>
#include "Enemy.h"
Enemy::Enemy(const std::string& enemyName, int enemyHealth, int playerDamage) : name(enemyName), health(enemyHealth), damage(playerDamage) {}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getHealth() const {
    return health;
}

void Enemy::decreaseHealth(int amount) {
    health -= amount;
}

int Enemy::getDamage() const {
    return damage;
}
