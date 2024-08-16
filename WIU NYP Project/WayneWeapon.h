#pragma once
#include "WayneGO.h"
class WayneWeapon : public WayneGO
{
private:
	int attack;

public:
	WayneWeapon(int a, int posW) : attack(a), WayneGO(posW) {}

	int getWeaponATK() const;

	//int attackUp();
	//void playerAtk();
};

