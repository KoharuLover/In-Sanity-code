#include "CGame.h"
#include "CPosition.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CKey.h"
#include "CWeapon.h"
#include "CCure.h"
#include "CStory.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

CGame::CGame()
{
}

bool CGame::isKeyPressed(int key)
{
	SHORT state = GetAsyncKeyState(key);
	return (state & 0x8000) != 0;
}

void CGame::waitForStart(int key)
{
	CStory* starter;
	starter = new CStory;
	starter->StartScreen();
	while (true) {
		if (isKeyPressed(' ')) {
			system("cls");
			delete starter;
			starter = nullptr;
			play();
			break;
		}
		Sleep(50); // Sleep for 100 milliseconds to reduce CPU usage
	}
}


void CGame::play()
{
	CStory* storyGame;
	storyGame = new CStory;

	storyGame->StartAct();

	delete storyGame;
	storyGame = nullptr;
	_CrtDumpMemoryLeaks();
}




