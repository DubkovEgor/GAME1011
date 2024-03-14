#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class Player;
class Enemy;

class GameObject {
public:
    virtual void NormalAttack() = 0;
    virtual ~GameObject() {}
};
#endif 
