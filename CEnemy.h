#pragma once
#include "CGameObject.h"

//FULLY FUNCTIONAL

class CPlayer;

class CEnemy : public CGameObject
{
private:

	int enemyHP;

public:

	CEnemy(int hp, int posE) : enemyHP(hp), CGameObject(posE) {}

	int getENHP() const;
	void setENHP(int hp);

	//int getENATK() const;
	//void setENATK(int atk); 

	bool attacking(CGameObject* target);        //checks if player is in same room as player
	void killPlayer(CPlayer* victim);

	void enemyMove();
	void moveToBase_E();
	void moveToLiving_E();
	void moveToKitchen_E();
	void moveToMB_E();
	void moveToExit_E();
};

