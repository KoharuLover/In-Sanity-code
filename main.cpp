#include <iostream>
#include "CGame.h"
#include "CPosition.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CKey.h"
#include "CWeapon.h"
#include "CCure.h"
#include "CStory.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Windows.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


//////////////////////////////////////////////////////////////////////////////////////////////////////
/****************************************************************************************************/
//    IN/SANITY GAME
/****************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string gay;

	std::cout << "Please enter full screen. Press enter any key afterwards.";

	std::cin >> gay;

	system("cls");


	CGame* game;
	game = new CGame;

	game->waitForStart(' ');


	delete game;
	game = nullptr;
	_CrtDumpMemoryLeaks();

}