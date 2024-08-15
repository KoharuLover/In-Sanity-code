#include "CPlayer.h"
#include <iostream>

int CPlayer::getSanity() const
{
    return sanity;
}

void CPlayer::setSanity(int s)
{
    sanity = s;
}

int CPlayer::getAttack() const
{
    return attack;
}

void CPlayer::setAttack(int a)
{
    attack = a;
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

void CPlayer::depleteSanity()
{
    setSanity(getSanity() - 20);
}

void CPlayer::moveToLiving()
{
    setObjPos(1);
}

void CPlayer::moveToKitchen()
{
    setObjPos(2);
}

void CPlayer::moveToMB()
{
    setObjPos(3);
}

void CPlayer::moveToBase()
{
    setObjPos(0);
}

void CPlayer::moveToExit()
{
    setObjPos(4);
}

//void CPlayer::unequip(CWeapon* weaponEqu)
//{
//    weaponInHand = nullptr;
//}
//
//bool CPlayer::isEquipped()
//{
//    if (!(weaponInHand = nullptr))
//    {
//        std::cout << "weapon equipped" << std::endl;
//        return true;
//    }
//    else
//    {
//        std::cout << "nothing equipped" << std::endl;
//        return false;
//    }
//    return false;
//}
//
//void CPlayer::tempDel()
//{
//    delete weaponInHand;
//    weaponInHand = nullptr;
//}
//void CPlayer::equip(CWeapon* weaponEquipped)
//{
//    if (!(weaponInHand = nullptr))
//    {
//        delete weaponInHand;
//    }
//    weaponInHand = weaponEquipped;
//}






