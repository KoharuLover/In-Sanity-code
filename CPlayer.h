#pragma once
#include "CGameObject.h"

class CPlayer : public CGameObject
{
private:
	
	int sanity;
	int attack;

public:

	CPlayer(int s, int a, int posP) : sanity(200), attack(0), CGameObject(posP) {}

	int getSanity() const;
	void setSanity(int s);
	void updateAttack(int a);
	void move(int newPos);

	


};

