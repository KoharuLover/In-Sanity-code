#include "CCure.h"

//FULLY FUNCTIONAL

int CCure::getRecoverAmt() const
{
    return recover;
}

void CCure::sanityUp(CPlayer* patient, int s)
{
    patient->setSanity(patient->getSanity() + s);
    if (patient->getSanity() > 200)
    {
        patient->setSanity(200);
    } 
}

bool CCure::isSameRoom(CPlayer* target)
{
    int isNear = target->getObjPos();

    if (isNear == getObjPos())
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void CCure::removeCure()
{
    setObjPos(5);  //sets it outside the map so u literally cant touch it no more
}

