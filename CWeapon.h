#pragma once
#include "CGameObject.h"

//NOT FUNCTIONAL YET

class CWeapon : public CGameObject
{
private:
	int attack;

public:
	CWeapon(int a, int posW) : attack(a), CGameObject(posW) {}

	int getWeaponATK() const;

	//int attackUp();
	//void playerAtk();
};

