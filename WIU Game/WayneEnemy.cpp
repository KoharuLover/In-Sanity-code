#include "WayneEnemy.h"
#include "Player.h"
#include <iostream>

int WayneEnemy::getENHP() const
{
    return enemyHP;
}

void WayneEnemy::setENHP(int hp)
{
    enemyHP = hp;
}

bool WayneEnemy::attacking(WayneGO* target)
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

void WayneEnemy::killPlayer(CPlayer* victim)
{
    victim->setSanity(victim->getSanity() * -30);
}
