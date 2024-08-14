#include "CGameObject.h"

int CGameObject::getObjPos() const
{
	return objectPos.getPos();
}

void CGameObject::setObjPos(int objPos)
{
	objectPos.setPos(objPos);
}

CPosition CGameObject::getPosition() const
{
	return objectPos;
}

void CGameObject::setPosition(int objPos)
{
	objectPos.setPos(objPos);
}

