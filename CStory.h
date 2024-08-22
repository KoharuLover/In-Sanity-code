#pragma once
#include <string>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include "DelayedText.h"
#include "WaiZhengRNG.h"
#include "WaiZhengClock.h"
#include "CCure.h"
#include "CPosition.h"
#include "CEnemy.h"
#include "CGameObject.h"
#include "CKey.h"
#include "CWeapon.h"
#include "Windows.h"
#include "EzenRLGL.h"
#include <conio.h>
#include <Windows.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class CPlayer;

class CStory
{
private:

	


public:

	CStory();


	void StartScreen();
	void StartAct();
	void Act1();  
	
	int Act2();

	void meltedEnd();
	void EscapeEnd();
	void caughtEnd();
	void NormalEnd();
	void InsanityEnd();
	void WaitEnd();

	void DogRLGL();
	void GardRLGL();


	void StartStealth(CEnemy* culprit, CPlayer* victim);
	void ClosetStealth(CEnemy* culprit, CPlayer* victim);
	void BedStealth(CEnemy* culprit, CPlayer* victim);

	void hideSuccess();
	void hideFailure();

	void closetFailure();

	void bedFailure();


	void playerDies();

	


	void gotoxy(int x, int y);
	void printDelayedText(const std::string& text);
	void hideCursor();
};

