#pragma once
#include "CGameObject.h"

class Weapon : public CGameObject
{
private:
	bool attack;

public:
	Weapon(int a, int posW) : attack(5), CGameObject(posW) {}
	int attackUp();

	

};

