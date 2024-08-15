#include "CEnemy.h"
#include "CPlayer.h"
#include <iostream>

int CEnemy::getENHP() const
{
    return enemyHP;
}

bool CEnemy::attacking(CGameObject* target)
{
    int targetPos = target->getObjPos();

    if (targetPos == getObjPos())
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void CEnemy::killPlayer(CPlayer* victim)
{
    victim->setSanity(victim->getSanity() * 0);
}



void CEnemy::setENHP(int hp)
{
    enemyHP = hp;
}
