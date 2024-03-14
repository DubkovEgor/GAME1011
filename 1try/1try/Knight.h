#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include "Player.h"

class Knight : public Player {
public:
    static std::string specialAttackName;

    Knight(const std::string& playerName, int playerHealth, int playerDamage);

    void NormalAttack() override;
    void SpecialAttack() override;
};

#endif 
