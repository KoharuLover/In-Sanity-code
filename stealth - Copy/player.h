#pragma once
#include <iostream>
#include <windows.h>
#include "CTimeClock.h"
class player
{
private:
	int stealthValue;
	std::string hideprompt;
	bool enemyAlerted;
public:
	player();
	void setStealth(int s);
	int getStealth();
	void hideAttempt();
};

