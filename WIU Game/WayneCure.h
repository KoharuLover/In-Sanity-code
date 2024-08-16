#pragma once
#include "WayneGO.h"
#include "Player.h"
class WayneCure : public WayneGO
{
private:

	int recover;

public:

	WayneCure(int s, int posC) : recover(s), WayneGO(posC) {}

	void sanityUp(CPlayer* patient, int s);

	bool isSameRoom(CPlayer* target);

};

