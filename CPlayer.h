#pragma once
#include "CGameObject.h"

class CPlayer : public CGameObject
{
private:
	
	int sanity;
	int attack;

public:

	CPlayer(int s, int a, int posP) : sanity(s), attack(a), CGameObject(posP) {}

	int getSanity() const;
	void setSanity(int s);
	void updateAttack(int a);
	bool playerAttacking(CGameObject* target);
	void move(int newPos);

	bool weaponEquipped(CGameObject* isEquipped);
	


};

