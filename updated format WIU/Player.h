#pragma once
#include "WayneGO.h"
#include "WayneWeapon.h"
#include "WayneKey.h"
#include "WayneEnemy.h"


//EQUIP FUNCTION IS NOT COMPLETED


class CPlayer : public WayneGO
{
private:

	int sanity;
	int attack;
	//CWeapon* weaponInHand;


public:

	CPlayer(int s, int a, int posP) : sanity(s), attack(a),WayneGO(posP) {}

	int getSanity() const;
	void setSanity(int s);
	void depleteSanity();

	int getAttack() const;
	void setAttack(int a);

	void updateAttack(int a);
	bool playerAttacking(WayneGO* target);


	void moveToLiving();
	void moveToKitchen();
	void moveToMB();
	void moveToBase();
	void moveToExit();

	//void unequip(CWeapon* weaponUnequipped);
	//void equip(CWeapon* weaponEquipped);
	//bool isEquipped();
	//
	//void tempDel();


};
