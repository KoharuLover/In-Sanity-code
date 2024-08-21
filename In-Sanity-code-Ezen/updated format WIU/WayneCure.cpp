#include "WayneCure.h"

void WayneCure::sanityUp(CPlayer* patient, int s)
{
    patient->setSanity(patient->getSanity() + s);
    if (patient->getSanity() > 200)
    {
        patient->setSanity(200);
    }
}

bool WayneCure::isSameRoom(CPlayer* target)
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

