#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "GameObject.h"

class Enemy : public GameObject {
protected:
    std::string name;
    int health;
    int damage;

public:
    Enemy(const std::string& enemyName, int enemyHealth, int playerDamage);

    virtual void NormalAttack() = 0;
    virtual void TauntPlayer() = 0;

    std::string getName() const;
    int getHealth() const;

    void decreaseHealth(int amount);
    int getDamage() const;
};

#endif 
