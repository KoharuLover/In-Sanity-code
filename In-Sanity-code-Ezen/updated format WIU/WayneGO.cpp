#include "WayneGO.h"

int WayneGO::getObjPos() const
{
    return objectPos.getPos();
}


void WayneGO::setObjPos(int objPos)
{
    objectPos.setPos(objPos);
}

WaynePos WayneGO::getPosition() const
{
    return objectPos;
}

void WayneGO::setPosition(int objPos)
{
    objectPos.setPos(objPos);
}
