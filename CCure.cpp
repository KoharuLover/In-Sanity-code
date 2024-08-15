#include "CCure.h"


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

//void CCure::nearBy(CPlayer* near)
//{
//    int isNear = near->getObjPos();
//    
//}
