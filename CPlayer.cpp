#include "CPlayer.h"

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

void CPlayer::move(int newPos)
{
    return;
}


