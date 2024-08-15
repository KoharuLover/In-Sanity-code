#pragma once
#include "CGameObject.h"
#include "CPlayer.h"

class CCure : public CGameObject
{
private:

	int recover;

public:

	CCure(int s, int posC) : recover(s), CGameObject(posC) {}

	void sanityUp(CPlayer* patient, int s);

	bool isSameRoom(CPlayer* target);

	/*void nearBy(CPlayer* near);*/


};

