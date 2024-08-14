#include "CCure.h"


void CCure::sanityUp(CPlayer* patient, int s)
{
    int isNearby = patient->getObjPos();
    
    if (isNearby == getObjPos())
    {
        patient->setSanity(patient->getSanity() + s);
        if (patient->getSanity() > 200)
        {
            patient->setSanity(200);
        }
    }
    
    
}

//void CCure::nearBy(CPlayer* near)
//{
//    int isNear = near->getObjPos();
//    
//}
