#ifndef ORC_H
#define ORC_H

#include "Enemy.h"

class Orc : public Enemy {
public:
    static std::string taunts[];

    Orc(int enemyHealth, int playerDamage);

    void NormalAttack() override;
    void TauntPlayer() override;
};

#endif
