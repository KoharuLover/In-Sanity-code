#include <iostream>
#include "CPosition.h"
#include "CGameObject.h"
#include "CPlayer.h"

int main()
{
	CGameObject* playerPtr = nullptr;   //creates pointer for player

	std::cout << "Start" << std::endl;

	char input;
	std::cin >> input;  //this will bee changed to handlekeypress 

	if (input == 1)
	{
		playerPtr = new CPlayer(200, 0, 0);    //spawns in player with 200 "sanity", 0 attack damage and position Value of 0//
	}
	else
	{
		return 0;
	}





	delete playerPtr;
	playerPtr = nullptr;
}