#include "CPlayer.h"
#include <iostream>

//CPlayer::CPlayer()
//{
//    sanity = 200;
//    attack = 0;
//}

int CPlayer::getSanity() const
{
    return sanity;
}

void CPlayer::setSanity(int s)
{
    sanity = s;
}

void CPlayer::updateAttack(int a)
{
    attack += a;
}

bool CPlayer::playerAttacking(CGameObject* target)
{
    int targetPos = target->getObjPos();
    if (targetPos == getObjPos())
    {
        std::cout << "player hits enemy" << std::endl;
        return true;
    }
    return false;

}

void CPlayer::move(int newPos)
{
    return;
}

bool CPlayer::weaponEquipped(CGameObject* isEquipped)
{
    return false;
}


