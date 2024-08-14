#pragma once
#include "CPosition.h"
class CGameObject
{
private:
	
	CPosition objectPos;
	
public:

	CGameObject(int objPos) : objectPos(objPos) {}

	int getObjPos() const;
	void setObjPos(int objPos);

	CPosition getPosition() const;
	void setPosition(int objPos);

};

