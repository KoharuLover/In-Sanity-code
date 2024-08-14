#include <iostream>
#include "CPosition.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CEnemy.h"
#include "CKey.h"
#include "CWeapon.h"
#include "CCure.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Windows.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));    //random seed generate
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	std::cout << "Start" << std::endl;
   

	char input;
	std::cin >> input;                                   //this will bee changed to handlekeypress 
	CPlayer* playerPtr = nullptr;                   //creates pointer for player
	if (input == 'a')
	{
		playerPtr = new CPlayer(200, 0, 0);             //spawns in player using pointer
		std::cout << "player created" << std::endl;
	}
	else
	{
		std::cout << "end" << std::endl;
	}

	CEnemy* enemyPtr[3];                                         //creates enemy pointers for 3 enemies
	for (int i = 0; i < 3; i++)                                  //spawns in 3 enemies using the pointers
	{
		enemyPtr[i] = new CEnemy(5, 200, i+1);
		std::cout << "enemy " << i << " created" << std::endl;
		/*if (i == 0)
		{
			enemyPtr[i] = new CEnemy(5, 200, 1);
			std::cout << "enemy " << i << " created" << std::endl;
		}
		if (i == 1)
		{
			enemyPtr[i] = new CEnemy(5, 200, 2);
			std::cout << "enemy " << i << " created" << std::endl;
		}
		if (i == 2)
		{
			enemyPtr[i] = new CEnemy(5, 200, 3);
			std::cout << "enemy " << i << " created" << std::endl;
		}*/
	}

	CKey* keyPtr;                                              //creates a key pointer

	int random_number = std::rand() % 3 + 1;                   //generates a random number from 1 to 3

	keyPtr = new CKey(random_number);                          //spawns key using pointer
	std::cout << "random = " << random_number << std::endl;
	std::cout << "key created" << std::endl;


	CWeapon* weaponPtr;                                        //creates a weapon pointer

	weaponPtr = new CWeapon(5, 0);                             //spawns weapon using pointer
	std::cout << "weapon created" << std::endl;


	CCure* curePtr[2];
	for (int i = 0; i < 2; i++)                                  //spawns in 3 enemies using the pointers
	{	
		int random;
		random = std::rand() % 3 + 1;                   //generates a random number from 1 to 3	

		curePtr[i] = new CCure(50, random);
		std::cout << "cure " << i << " created" << std::endl;
		/*if (i == 0)
		{
			curePtr[i] = new CCure(50, random);
			std::cout << "cure " << i << " created" << std::endl;
		}
		if (i == 1)
		{
			curePtr[i] = new CCure(50, random);
			std::cout << "cure " << i << " created" << std::endl;
		}*/
		std::cout << random << std::endl;
	}

/********************************************************************************************************************/



	std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;     //Original sanity level
	std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;



	// My Room (0), Living Room (1), Kitchen (2), Master Bedroom (3), Exit (4)



    std::string where;
	std::cout << "Where would you like to go?" << std::endl;
	Sleep(2000);
	std::cout << "Living Room <living>" << std::endl;
	Sleep(1000);
	std::cout << "Stay <stay>" << std::endl;

	std::cin >> where;
	if (where == "living")
	{
		playerPtr->setSanity(playerPtr->getSanity() - 10);
		playerPtr->setObjPos(1);
		std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
		std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
		Sleep(4000);

		std::cout << "You entered the living room. Its eerie." << std::endl;
		Sleep(3000);

		

		for (int i = 0; i < 3; i++)
		{		
			std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;		
		}

		Sleep(2000);
		std::cout << "Where would you like to go?" << std::endl;
		Sleep(2000);
		std::cout << "Kitchen <kitchen>" << std::endl;
		Sleep(1000);
		std::cout << "Master Bedroom <bedroom>" << std::endl;
		Sleep(1000);
		std::cout << "My Room <base>" << std::endl;
		Sleep(1000);
		std::cout << "Stay <stay>" << std::endl;
		Sleep(1000);
		std::cout << "LEAVE <leave>" << std::endl;
		
		std::cin >> where;
		if (where == "kitchen")
		{
			playerPtr->setSanity(playerPtr->getSanity() - 10);
			playerPtr->setObjPos(2);
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(4000);

			std::cout << "You entered the kitchen. Its quiet." << std::endl;
			
			for (int i = 0; i < 3; i++)
			{
				std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;
			}
		}
		else if (where == "bedroom")
		{
			playerPtr->setSanity(playerPtr->getSanity() - 10);
			playerPtr->setObjPos(3);
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(4000);

			std::cout << "You entered the master bedroom. Its silent." << std::endl;
			
			for (int i = 0; i < 3; i++)
			{
				std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;
			}
		}
		else if (where == "base")
		{
			playerPtr->setSanity(playerPtr->getSanity() - 10);
			playerPtr->setObjPos(0);
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(4000);

			std::cout << "You entered your room. You feel safe." << std::endl;
			
			for (int i = 0; i < 3; i++)
			{
				std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;
			}
		}
		else if (where == "leave")
		{   
			playerPtr->setObjPos(4);
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(4000);

			std::cout << "you left..." << std::endl;
			
			for (int i = 0; i < 3; i++)
			{
				std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;
			}
			std::cout << "you left..." << std::endl;
		}

		else
		{
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(4000);

			std::cout << "Stay." << std::endl;
			for (int i = 0; i < 3; i++)
			{
				std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
		std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
		Sleep(4000);

		std::cout << "Stay." << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << enemyPtr[i]->attacking(playerPtr) << std::endl;
		}
	}
	
	/*std::cout << playerPtr->getObjPos() << std::endl;*/
	//std::cout << enemyPtr[0]->attacking(playerPtr) << std::endl;



/********************************************************************************************************************/

	
	//DESTRUCTORS//


	delete playerPtr;                                           //destroys player
	playerPtr = nullptr;
	std::cout << "player destroyed" << std::endl;
	for (int i = 0; i < 3; i++)                                   //destroys all enemies
	{
		delete enemyPtr[i];
		enemyPtr[i] = nullptr;
		std::cout << "enemy " << i << " destroyed" << std::endl;
	}
	delete keyPtr;                                                  //destroys key
	keyPtr = nullptr;

	std::cout << "key destroyed" << std::endl;

	delete weaponPtr;                                                 //destroys weapon
	weaponPtr = nullptr;

	std::cout << "weapon destroyed" << std::endl;

	for (int i = 0; i < 2; i++)                                   //destroys all cures
	{
		delete curePtr[i];
		curePtr[i] = nullptr;
		std::cout << "cure " << i << " destroyed" << std::endl;
	}
}