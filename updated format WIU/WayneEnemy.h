#pragma once
#include "WayneGO.h"

class CPlayer;
class WayneEnemy : public WayneGO
{
private:

	int enemyHP;

public:

	WayneEnemy(int hp, int posE) : enemyHP(hp), WayneGO(posE) {}

	int getENHP() const;
	void setENHP(int hp);

	bool attacking(WayneGO* target);        //checks if player is in same room as player
	void killPlayer(CPlayer* victim);
};

