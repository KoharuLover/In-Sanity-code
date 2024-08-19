#include <iostream>
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


//////////////////////////////////////////////////////////////////////////////////////////////////////
/****************************************************************************************************/
//    EXAMPLE FOR USING THE OBJECTS AND FUNCTIONS FROM THE CLASSES
//    (player, enemy, cure) [key and weapon is still unusuable]
/****************************************************************************************************/
//////////////////////////////////////////////////////////////////////////////////////////////////////


bool IsKeyPressed(int key) 
{
	SHORT state = GetAsyncKeyState(key);
	return (state & 0x8000) != 0;
}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string gay;

	std::cout << "Please enter full screen.";

	std::cin >> gay;

	system("cls");

	CStory* test;
	test = new CStory;

	test->StartAct();


	
   

	char input;
	std::cin >> input;                              

	CPlayer* playerPtr = nullptr;                   //creates pointer for player

	if (input == 'a')
	{
		system("cls");
		playerPtr = new CPlayer(200, 0, 0, nullptr, nullptr);             //spawns in player using pointer
		
		std::cout << "player created" << std::endl;
		std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
		std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;

		if (playerPtr->isEquipped() == true)
		{
			std::cout << "weapon equipped." << std::endl;
		}
		else
		{
			std::cout << "nothing equipped." << std::endl;
		}
	}
	else
	{
		std::cout << "end" << std::endl;
	}

	Sleep(3000);

	CEnemy* enemyPtr[2];                                         //creates enemy pointers for 3 enemies
	for (int i = 0; i < 2; i++)                                  //spawns in 3 enemies using the pointers
	{
		enemyPtr[i] = new CEnemy(200, i+2);
		std::cout << "enemy " << i << " created" << std::endl;
		std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;
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

	Sleep(3000);

	CKey* keyPtr;                                              //creates a key pointer

	int random_number = std::rand() % 3 + 1;                   //generates a random number from 1 to 3

	keyPtr = new CKey(random_number);                          //spawns key using pointer
	std::cout << "key created" << std::endl;
	std::cout << "Key Location = " << random_number << std::endl;

	Sleep(3000);

	CWeapon* weaponPtr;                                        //creates a weapon pointer

	weaponPtr = new CWeapon(200, 2);                             //spawns weapon using pointer
	std::cout << "weapon created" << std::endl;
	std::cout << "Weapon Location = " << weaponPtr->getObjPos() << std::endl;

	Sleep(3000);

	CCure* curePtr[2];
	for (int i = 0; i < 2; i++)                                  //spawns in 3 enemies using the pointers
	{	
		srand(static_cast<unsigned int>(time(0)));
		int random;
		int random2;
		do
		{
			random = 2;                             //always one cure in kitchen
			random2 = std::rand() % 3 + 1;          //generates a random number from 1 to 3

		} while (random == random2);

		//curePtr[i] = new CCure(50, random);
		//std::cout << "cure " << i << " created" << std::endl;
		if (i == 0)
		{
			curePtr[0] = new CCure(50, random);
			std::cout << "cure 0 created" << std::endl;
			std::cout << "cure 0 location = " << random << std::endl;
		}

		if (i == 1)
		{
			curePtr[1] = new CCure(50, random2);
			std::cout << "cure 1 created" << std::endl;
			std::cout << "cure 1 location = " << random2 << std::endl;
		}
	
		
	}

	Sleep(5000);


/********************************************************************************************************************/



	//std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;     //Original sanity level
	//std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;


	std::string readyInput;
	std::cout << "Check?" << std::endl;
	std::cin >> readyInput;

	if (readyInput == "check")
	{
		system("cls");


		////// My Room (0), Living Room (1), Kitchen (2), Master Bedroom (3), Exit (4)//////////////////////////////////////////////////////////


		std::string where;
		std::cout << "Where would you like to go?" << std::endl;
		Sleep(2000);
		std::cout << "Living Room <living>" << std::endl;
		Sleep(1000);
		std::cout << "Stay <stay>" << std::endl;

		std::cin >> where;
		if (where == "living")
		{
			system("cls");
			playerPtr->depleteSanity();
			playerPtr->moveToLiving();
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;



			Sleep(1000);
			for (int i = 0; i < 2; i++)
			{
				enemyPtr[i]->enemyMove();
				std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

				Sleep(2000);

				if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
				{
					std::string how;
					std::cout << "Kill? <kill/hold>" << std::endl;
					std::cin >> how;
					if (how == "kill")
					{
						if (playerPtr->isEquipped() == true)
						{
							for (int j = 0; j < 2; j++)
							{
								playerPtr->useWeapon(enemyPtr[j]);
								std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
							}
						}
						else
						{
							std::cout << "I can't kill without a weapon." << std::endl;
						}

					}
					else
					{
						std::cout << "You held back." << std::endl;
					}
				}
				else
				{
					std::cout << "There are no monsters nearby." << std::endl;
				}

			}

			Sleep(3000);


			if (keyPtr->getObjPos() == playerPtr->getObjPos())
			{
				system("cls");
				std::string what;
				std::cout << "Pick up key? <yes/no>";
				std::cin >> what;
				if (what == "yes")
				{
					playerPtr->equip2(keyPtr);
					if (playerPtr->isEquipped2() == true)
					{
						std::cout << "key equipped" << std::endl;
					}
					else
					{
						std::cout << "nothing equipped" << std::endl;
					}
				}
				else
				{
					system("cls");
					std::cout << "You're going to need it." << std::endl;
					Sleep(5000);
				}
			}



			///////////////////////////////////////////////////////////////////
			//
			//
			//
			//std::string how;
			//std::cout << "Kill? <kill/hold>" << std::endl;
			//std::cin >> how;
			//if (how == "kill")
			//{
			//	if (playerPtr->isEquipped() == true)
			//	{
			//		for (int i = 0; i < 2; i++)
			//		{
			//			playerPtr->useWeapon(enemyPtr[i]);
			//			std::cout << "Enemy " << i << " HP: " << enemyPtr[i]->getENHP() << std::endl;
			//		}
			//	}
			//	else
			//	{
			//		std::cout << "I can't kill without a weapon." << std::endl;
			//	}
			//
			//}
			//else
			//{
			//	std::cout << "You held back." << std::endl;
			//}
			//
			///////////////////////////////////////////////////////////////


			system("cls");

			Sleep(3000);
			std::cout << "You entered the living room. Its eerie." << std::endl;
			Sleep(3000);
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
			std::cout << " " << std::endl;

			Sleep(2000);

			if (curePtr[0]->isSameRoom(playerPtr) == true)
			{
				curePtr[0]->sanityUp(playerPtr, 50);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				Sleep(1000);
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(1000);
				std::cout << "cure 0 consumed" << std::endl;
			}
			if (curePtr[1]->isSameRoom(playerPtr) == true)
			{
				curePtr[1]->sanityUp(playerPtr, 50);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				Sleep(1000);
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(1000);
				std::cout << "cure 1 consumed" << std::endl;
			}
			if (curePtr[0]->isSameRoom(playerPtr) == false)
			{
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				Sleep(1000);
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(1000);
				std::cout << "no cure 0" << std::endl;
			}
			if (curePtr[1]->isSameRoom(playerPtr) == false)
			{
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				Sleep(1000);
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(1000);
				std::cout << "no cure 1" << std::endl;
			}

			Sleep(3000);


			for (int i = 0; i < 2; i++)
			{
				if (enemyPtr[i]->attacking(playerPtr) == true)
				{
					enemyPtr[i]->killPlayer(playerPtr);
					std::cout << "enemy " << i << " has killed you." << std::endl;
				}
				else
				{
					std::cout << "safe from enemy " << i << std::endl;
				}
			}
			Sleep(3000);
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(3000);


			std::cin >> where;
			if (where == "kitchen")
			{
				system("cls");
				playerPtr->depleteSanity();
				playerPtr->moveToKitchen();
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;

				Sleep(1000);

				std::cout << "You entered the kitchen. Its quiet." << std::endl;
				Sleep(4000);


				///////////////////////////////////////////////////////////////////

				if (weaponPtr->getObjPos() == playerPtr->getObjPos())
				{
					system("cls");
					std::string what;
					std::cout << "Pick up weapon? <yes/no>";
					std::cin >> what;
					if (what == "yes")
					{
						playerPtr->equip(weaponPtr);
						if (playerPtr->isEquipped() == true)
						{
							std::cout << "weapon equipped" << std::endl;
						}
						else
						{
							std::cout << "nothing equipped" << std::endl;
						}
					}
					else
					{
						std::cout << "You need protection." << std::endl;
					}
				}
				Sleep(3000);
				
				system("cls");

				for (int i = 0; i < 2; i++)
				{

					enemyPtr[i]->enemyMove();
					std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

					Sleep(2000);

					if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
					{
						std::string how;
						std::cout << "Kill? <kill/hold>" << std::endl;
						std::cin >> how;
						if (how == "kill")
						{
							if (playerPtr->isEquipped() == true)
							{
								for (int j = 0; j < 2; j++)
								{
									playerPtr->useWeapon(enemyPtr[j]);
									std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
								}
							}
							else
							{
								std::cout << "I can't kill without a weapon." << std::endl;
							}

						}
						else
						{
							std::cout << "You held back." << std::endl;
						}
					}
					else
					{
						std::cout << "There are no monsters nearby." << std::endl;
					}

				}

				Sleep(3000);

				if (keyPtr->getObjPos() == playerPtr->getObjPos())
				{
					system("cls");
					std::string what;
					std::cout << "Pick up key? <yes/no>";
					std::cin >> what;
					if (what == "yes")
					{
						playerPtr->equip2(keyPtr);
						if (playerPtr->isEquipped2() == true)
						{
							std::cout << "key equipped" << std::endl;
						}
						else
						{
							std::cout << "nothing equipped" << std::endl;
						}
					}
					else
					{
						system("cls");
						std::cout << "You're going to need it." << std::endl;
					}
				}

				Sleep(3000);
				///////////////////////////////////////////////////////////////


				if (curePtr[0]->isSameRoom(playerPtr) == true)
				{
					curePtr[0]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					Sleep(1000);
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					Sleep(1000);
					std::cout << "cure 0 consumed" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == true)
				{
					curePtr[1]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					Sleep(1000);
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					Sleep(1000);
					std::cout << "cure 1 consumed" << std::endl;
				}
				if (curePtr[0]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					Sleep(1000);
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					Sleep(1000);
					std::cout << "no cure 0" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					Sleep(1000);
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					Sleep(1000);
					std::cout << "no cure 1" << std::endl;
				}

				Sleep(3000);
				for (int i = 0; i < 2; i++)
				{
					if (enemyPtr[i]->attacking(playerPtr) == true)
					{
						enemyPtr[i]->killPlayer(playerPtr);
						std::cout << "enemy " << i << " has killed you." << std::endl;
					}
					else
					{
						std::cout << "safe from enemy " << i << std::endl;
					}
				}
				Sleep(3000);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(3000);
				/*for (int i = 0; i < 2; i++)
				{
					if (curePtr[i]->isSameRoom(playerPtr) == true)
					{
						curePtr[i]->sanityUp(playerPtr, 50);
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					}
					else
					{
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
						std::cout << "no cure in room" << std::endl;
					}
				}*/
			}
			else if (where == "bedroom")
			{
				system("cls");
				playerPtr->depleteSanity();
				playerPtr->moveToMB();
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;

				Sleep(1000);

				system("cls");

				for (int i = 0; i < 2; i++)
				{
					enemyPtr[i]->enemyMove();
					std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

					Sleep(2000);

					if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
					{
						std::string how;
						std::cout << "Kill? <kill/hold>" << std::endl;
						std::cin >> how;
						if (how == "kill")
						{
							if (playerPtr->isEquipped() == true)
							{
								for (int j = 0; j < 2; j++)
								{
									playerPtr->useWeapon(enemyPtr[j]);
									std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
								}
							}
							else
							{
								std::cout << "I can't kill without a weapon." << std::endl;
							}

						}
						else
						{
							std::cout << "You held back." << std::endl;
						}
					}
					else
					{
						std::cout << "There are no monsters nearby." << std::endl;
					}

				}

				Sleep(3000);

				if (keyPtr->getObjPos() == playerPtr->getObjPos())
				{
					system("cls");
					std::string what;
					std::cout << "Pick up key? <yes/no>";
					std::cin >> what;
					if (what == "yes")
					{
						playerPtr->equip2(keyPtr);
						if (playerPtr->isEquipped2() == true)
						{
							std::cout << "key equipped" << std::endl;
						}
						else
						{
							std::cout << "nothing equipped" << std::endl;
						}
					}
					else
					{
						system("cls");
						std::cout << "You're going to need it." << std::endl;
					}
				}

				Sleep(3000);

				system("cls");

				std::cout << "You entered the master bedroom. Its silent." << std::endl;
				Sleep(4000);


				if (curePtr[0]->isSameRoom(playerPtr) == true)
				{
					curePtr[0]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "cure 0 consumed" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == true)
				{
					curePtr[1]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "cure 1 consumed" << std::endl;
				}
				if (curePtr[0]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "no cure 0" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "no cure 1" << std::endl;
				}
				/*for (int i = 0; i < 2; i++)
				{
					if (curePtr[i]->isSameRoom(playerPtr) == true)
					{
						curePtr[i]->sanityUp(playerPtr, 50);
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					}
					else
					{
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
						std::cout << "no cure in room" << std::endl;
					}
				}*/

				Sleep(3000);

				for (int i = 0; i < 2; i++)
				{
					if (enemyPtr[i]->attacking(playerPtr) == true)
					{
						enemyPtr[i]->killPlayer(playerPtr);
						std::cout << "enemy " << i << " has killed you." << std::endl;
					}
					else
					{
						std::cout << "safe from enemy " << i << std::endl;
					}
				}
				Sleep(3000);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(3000);
			}
			else if (where == "base")
			{
				system("cls");
				playerPtr->depleteSanity();
				playerPtr->moveToBase();
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;

				Sleep(1000);

				system("cls");

				for (int i = 0; i < 2; i++)
				{
					enemyPtr[i]->enemyMove();
					std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

					Sleep(2000);

					if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
					{
						std::string how;
						std::cout << "Kill? <kill/hold>" << std::endl;
						std::cin >> how;
						if (how == "kill")
						{
							if (playerPtr->isEquipped() == true)
							{
								for (int j = 0; j < 2; j++)
								{
									playerPtr->useWeapon(enemyPtr[j]);
									std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
								}
							}
							else
							{
								std::cout << "I can't kill without a weapon." << std::endl;
							}

						}
						else
						{
							std::cout << "You held back." << std::endl;
						}
					}
					else
					{
						std::cout << "There are no monsters nearby." << std::endl;
					}

				}

				Sleep(3000);

				if (keyPtr->getObjPos() == playerPtr->getObjPos())
				{
					system("cls");
					std::string what;
					std::cout << "Pick up key? <yes/no>";
					std::cin >> what;
					if (what == "yes")
					{
						playerPtr->equip2(keyPtr);
						if (playerPtr->isEquipped2() == true)
						{
							std::cout << "key equipped" << std::endl;
						}
						else
						{
							std::cout << "nothing equipped" << std::endl;
						}
					}
					else
					{
						system("cls");
						std::cout << "You're going to need it." << std::endl;
					}
				}

				Sleep(3000);

				system("cls");

				std::cout << "You entered your room. You feel safe." << std::endl;
				Sleep(4000);


				if (curePtr[0]->isSameRoom(playerPtr) == true)
				{
					curePtr[0]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "cure 0 consumed" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == true)
				{
					curePtr[1]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "cure 1 consumed" << std::endl;
				}
				if (curePtr[0]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "no cure 0" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "no cure 1" << std::endl;
				}
				/*for (int i = 0; i < 2; i++)
				{
					if (curePtr[i]->isSameRoom(playerPtr) == true)
					{
						curePtr[i]->sanityUp(playerPtr, 50);
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					}
					else
					{
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
						std::cout << "no cure in room" << std::endl;
					}
				}*/

				Sleep(3000);
				for (int i = 0; i < 2; i++)
				{
					if (enemyPtr[i]->attacking(playerPtr) == true)
					{
						enemyPtr[i]->killPlayer(playerPtr);
						std::cout << "enemy " << i << " has killed you." << std::endl;
					}
					else
					{
						std::cout << "safe from enemy " << i << std::endl;
					}
				}
				Sleep(3000);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(3000);
			}
			else if (where == "leave")
			{
				system("cls");
				playerPtr->moveToExit();
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;


				Sleep(4000);

				system("cls");

				for (int i = 0; i < 2; i++)
				{
					enemyPtr[i]->enemyMove();
					std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

					Sleep(2000);

					if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
					{
						std::string how;
						std::cout << "Kill? <kill/hold>" << std::endl;
						std::cin >> how;
						if (how == "kill")
						{
							if (playerPtr->isEquipped() == true)
							{
								for (int j = 0; j < 2; j++)
								{
									playerPtr->useWeapon(enemyPtr[j]);
									std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
								}
							}
							else
							{
								std::cout << "I can't kill without a weapon." << std::endl;
							}

						}
						else
						{
							std::cout << "You held back." << std::endl;
						}
					}
					else
					{
						std::cout << "There are no monsters nearby." << std::endl;
					}

				}

				Sleep(3000);

				if (keyPtr->getObjPos() == playerPtr->getObjPos())
				{
					system("cls");
					std::string what;
					std::cout << "Pick up key? <yes/no>";
					std::cin >> what;
					if (what == "yes")
					{
						playerPtr->equip2(keyPtr);
						if (playerPtr->isEquipped2() == true)
						{
							std::cout << "key equipped" << std::endl;
						}
						else
						{
							std::cout << "nothing equipped" << std::endl;
						}
					}
					else
					{
						system("cls");
						std::cout << "You're going to need it." << std::endl;
					}
				}

				Sleep(3000);

				system("cls");

				std::cout << "you left..." << std::endl;


				if (curePtr[0]->isSameRoom(playerPtr) == true)
				{
					curePtr[0]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "cure 0 consumed" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == true)
				{
					curePtr[1]->sanityUp(playerPtr, 50);
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "cure 1 consumed" << std::endl;
				}
				if (curePtr[0]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "no cure 0" << std::endl;
				}
				if (curePtr[1]->isSameRoom(playerPtr) == false)
				{
					std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
					std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					std::cout << "no cure 1" << std::endl;
				}
				/*for (int i = 0; i < 2; i++)
				{
					if (curePtr[i]->isSameRoom(playerPtr) == true)
					{
						curePtr[i]->sanityUp(playerPtr, 50);
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
					}
					else
					{
						std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
						std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
						std::cout << "no cure in room" << std::endl;
					}
				}*/

				Sleep(3000);
				for (int i = 0; i < 2; i++)
				{
					if (enemyPtr[i]->attacking(playerPtr) == true)
					{
						enemyPtr[i]->killPlayer(playerPtr);
						std::cout << "enemy " << i << " has killed you." << std::endl;
					}
					else
					{
						std::cout << "safe from enemy " << i << std::endl;
					}
				}
				Sleep(3000);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(3000);
			}

			else
			{
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;


				Sleep(4000);

				system("cls");

				for (int i = 0; i < 2; i++)
				{
					enemyPtr[i]->enemyMove();
					std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

					Sleep(2000);

					if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
					{
						std::string how;
						std::cout << "Kill? <kill/hold>" << std::endl;
						std::cin >> how;
						if (how == "kill")
						{
							if (playerPtr->isEquipped() == true)
							{
								for (int j = 0; j < 2; j++)
								{
									playerPtr->useWeapon(enemyPtr[j]);
									std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
								}
							}
							else
							{
								std::cout << "I can't kill without a weapon." << std::endl;
							}

						}
						else
						{
							std::cout << "You held back." << std::endl;
						}
					}
					else
					{
						std::cout << "There are no monsters nearby." << std::endl;
					}

				}

				Sleep(5000);

				system("cls");

				std::cout << "Stay." << std::endl;


				for (int i = 0; i < 2; i++)
				{
					if (enemyPtr[i]->attacking(playerPtr) == true)
					{
						enemyPtr[i]->killPlayer(playerPtr);
						std::cout << "enemy " << i << " has killed you." << std::endl;
					}
					else
					{
						std::cout << "safe from enemy " << i << std::endl;
					}
				}
				Sleep(3000);
				std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
				std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
				Sleep(3000);
			}
		}
		else
		{
			system("cls");
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "player Position = " << playerPtr->getObjPos() << std::endl;

			Sleep(4000);

			system("cls");

			for (int i = 0; i < 2; i++)
			{
				enemyPtr[i]->enemyMove();
				std::cout << "Enemy " << i << " Position = " << enemyPtr[i]->getObjPos() << std::endl;

				Sleep(2000);

				if (enemyPtr[i]->getObjPos() == playerPtr->getObjPos())
				{
					std::string how;
					std::cout << "Kill? <kill/hold>" << std::endl;
					std::cin >> how;
					if (how == "kill")
					{
						if (playerPtr->isEquipped() == true)
						{
							for (int j = 0; j < 2; j++)
							{
								playerPtr->useWeapon(enemyPtr[j]);
								std::cout << "Enemy " << j << " HP: " << enemyPtr[j]->getENHP() << std::endl;
							}
						}
						else
						{
							std::cout << "I can't kill without a weapon." << std::endl;
						}

					}
					else
					{
						std::cout << "You held back." << std::endl;
					}
				}
				else
				{
					std::cout << "There are no monsters nearby." << std::endl;
				}

			}



			Sleep(5000);

			system("cls");

			std::cout << "Stay." << std::endl;


			for (int i = 0; i < 2; i++)
			{
				if (enemyPtr[i]->attacking(playerPtr) == true)
				{
					enemyPtr[i]->killPlayer(playerPtr);
					std::cout << "enemy " << i << " has killed you." << std::endl;
				}
				else
				{
					std::cout << "safe from enemy " << i << std::endl;
				}
			}
			Sleep(3000);
			std::cout << "Player <Sanity> = " << playerPtr->getSanity() << std::endl;
			std::cout << "Player Position = " << playerPtr->getObjPos() << std::endl;
			Sleep(3000);
		}


		if (playerPtr->getSanity() == 0)
		{
			system("cls");
			std::cout << "Player has died." << std::endl;
		}

		Sleep(2000);

		for (int i = 0; i < 2; i++)
		{
			if (enemyPtr[i]->getENHP() == 0)
			{
				system("cls");
				std::cout << "Enemy " << i << " is dead." << std::endl;
			}
		}



		Sleep(5000);

		system("cls");

		//DESTRUCTORS//


		//playerPtr->unequip();

		delete playerPtr;                                           //destroys player
		playerPtr = nullptr;
		std::cout << "player destroyed" << std::endl;
		for (int i = 0; i < 2; i++)                                   //destroys all enemies
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
	else
	{
		//DESTRUCTORS//


		//playerPtr->unequip();

		delete playerPtr;                                           //destroys player
		playerPtr = nullptr;
		std::cout << "player destroyed" << std::endl;
		for (int i = 0; i < 2; i++)                                   //destroys all enemies
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

/********************************************************************************************************************/

	
	//DESTRUCTORS//

	
	//playerPtr->unequip();
	//
	//delete playerPtr;                                           //destroys player
	//playerPtr = nullptr;
	//std::cout << "player destroyed" << std::endl;
	//for (int i = 0; i < 2; i++)                                   //destroys all enemies
	//{
	//	delete enemyPtr[i];
	//	enemyPtr[i] = nullptr;
	//	std::cout << "enemy " << i << " destroyed" << std::endl;
	//}
	//delete keyPtr;                                                  //destroys key
	//keyPtr = nullptr;
	//
	//std::cout << "key destroyed" << std::endl;
	//
	//delete weaponPtr;                                                 //destroys weapon
	//weaponPtr = nullptr;
	//
	//std::cout << "weapon destroyed" << std::endl;
	//
	//for (int i = 0; i < 2; i++)                                   //destroys all cures
	//{
	//	delete curePtr[i];
	//	curePtr[i] = nullptr;
	//	std::cout << "cure " << i << " destroyed" << std::endl;
	//}
}