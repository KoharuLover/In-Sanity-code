#pragma once
#include "WaynePos.h"
class WayneGO
{
private:

	WaynePos objectPos;

public:

	WayneGO(int objPos) : objectPos(objPos) {}

	int getObjPos() const;
	void setObjPos(int objPos);

	WaynePos getPosition() const;
	void setPosition(int objPos);
};

