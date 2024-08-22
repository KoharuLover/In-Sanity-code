#pragma once
#include "CGameObject.h"
#include "CPlayer.h"

//FULLY FUNCTIONAL

class CCure : public CGameObject
{
private:

	int recover;

public:

	CCure(int s, int posC) : recover(s), CGameObject(posC) {}

	int getRecoverAmt() const;

	void sanityUp(CPlayer* patient, int s);

	bool isSameRoom(CPlayer* target);

	void removeCure();

	/*void nearBy(CPlayer* near);*/


};

