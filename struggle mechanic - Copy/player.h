#pragma once
#include <iostream>
#include "CTimeClock.h"
#include "windows.h"
class player
{
private:
	int inputCount;
	double sanityDrain;
	bool keypressed;

public:
	player();
	void struggle();
};

