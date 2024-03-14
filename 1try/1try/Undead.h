#ifndef UNDEAD_H
#define UNDEAD_H

#include "Enemy.h"

class Undead : public Enemy {
public:
    static std::string taunts[];

    Undead(int enemyHealth, int playerDamage);

    void NormalAttack() override;
    void TauntPlayer() override;
};

#endif 
