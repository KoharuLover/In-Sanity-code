#pragma once
#include "CGameObject.h"
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

};

