#pragma once
#include <iostream>
#include "Windows.h"

class CGame
{
private:


public:

	CGame();

	void play();
	bool isKeyPressed(int key);
	void waitForStart(int key);
};

