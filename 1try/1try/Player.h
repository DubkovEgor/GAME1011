#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "GameObject.h"

class Player : public GameObject {
protected:
    std::string name;
    int health;
    int damage;

public:
    Player(const std::string& playerName, int playerHealth, int playerDamage);

    virtual void NormalAttack() = 0;
    virtual void SpecialAttack() = 0;

    std::string getName() const;
    int getHealth() const;

    void decreaseHealth(int amount);
    int getDamage() const;
};

#endif 
