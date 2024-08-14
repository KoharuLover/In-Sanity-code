#pragma once
#include "CGameObject.h"

class CEnemy : public CGameObject
{
private:

	int enemyHP;
	int enemyATK;

public:

	CEnemy(int hp, int atk, int posE) : enemyHP(hp), enemyATK(atk), CGameObject(posE) {}

	int getENHP() const;
	void setENHP(int hp);

	int getENATK() const;
	void setENATK(int atk); 

	bool attacking(CGameObject* target);

};

