#include "CEnemy.h"
#include <iostream>

int CEnemy::getENHP() const
{
    return enemyHP;
}

int CEnemy::getENATK() const
{
    return enemyATK;
}

void CEnemy::setENATK(int atk)
{
    enemyATK = atk;
}

bool CEnemy::attacking(CGameObject* target)
{
    int targetPos = target->getObjPos();

    if (targetPos == getObjPos())
    {
        std::cout << "enemy hits player" << std::endl;
        return true;
    }
    else
    {
        std::cout << "enemy is dormant" << std::endl;
        return false;
    }
    return false;
}

void CEnemy::setENHP(int hp)
{
    enemyHP = hp;
}
