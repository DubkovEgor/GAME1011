#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include "Player.h"

class Wizard : public Player {
public:
    static std::string specialAttackName;

    Wizard(const std::string& playerName, int playerHealth, int playerDamage);

    void NormalAttack() override;
    void SpecialAttack() override;
};

#endif 
