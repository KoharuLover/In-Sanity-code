#pragma once
#include "CGameObject.h"
#include "CWeapon.h"
#include "CKey.h"
#include "CEnemy.h"


//EQUIP FUNCTION IS NOT COMPLETED


class CPlayer : public CGameObject
{
private:
	
	int sanity;
	int attack;
	CWeapon* weaponInHand;
	CKey* keyInHand;


public:

	CPlayer(int s, int a, int posP, CWeapon* weaponEquipped, CKey* keyEquipped) : sanity(s), attack(a), CGameObject(posP), weaponInHand(weaponEquipped), keyInHand(keyEquipped) {}

	int getSanity() const;
	void setSanity(int s);
	void depleteSanity();

	int getAttack() const;
	void setAttack(int a);

	void updateAttack(int a);
	bool playerAttacking(CGameObject* target);


	void moveToLiving();
	void moveToKitchen();
	void moveToMB();
	void moveToBase();
	void moveToExit();

	void unequip();

	void equip(CWeapon* weaponEquipped);
	bool isEquipped();
	void useWeapon(CEnemy* badGuy);

	void equip2(CKey* keyEquipped);
	bool isEquipped2();
	void useKey(CKey* keyEquipped);

};

