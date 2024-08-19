#include "CEnemy.h"
#include "CPlayer.h"
#include <iostream>

//FULLY FUNCTIONAL

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

void CEnemy::enemyMove()
{   
    srand(static_cast<unsigned int>(time(0)));

    int movement = rand() % 3 - 1;
    if (movement == 0)
    {
        setObjPos(1);
    }
    else if (movement == 1)
    {
        setObjPos(2);
    }
    else if (movement == -1)
    {
        setObjPos(3);
    }
    
    
}



void CEnemy::setENHP(int hp)
{
    enemyHP = hp;
}
