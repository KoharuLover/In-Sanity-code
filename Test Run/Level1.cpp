#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "Player.h"

Level1::Level1()
{

}

void Level1::loadLevel()
{
   /* setPlayer();*/
    printStory();
  /*  startLevel();*/

}

void Level1::startLevel()
{
    player->drawHud();
    console();
}

void Level1::printStory()
{
    
}

void Level1::console()
{
    string cmd = "nothing";

    //Checking Mechanic Goes Here

    srand(time(0));

    while (player->getHealth() > 0)
    {
        std::cout << "Type 'move' to move forward or 'wait' to recover.\n";

        while (cmd != "move" && cmd != "wait")
        {
            std::cout << ">"; getline(cin, cmd);
        }

        if (cmd == "move")
        {
            std::cout << "Now walking...\n";
            Sleep(3000);
            std::cout <<" Austin moved few steps forward and ";

            //Implement Checking Mechanic

            /*RNG = 1 + (rand() % 3);
            potionRNG = 1 + (rand() % 5);*/


            //if (RNG == 1 || RNG == 2 && potionRNG != 2)
            //{
            //    std::cout << "nothing happened.\n";
            //    std::cout << "-------------------------------------------------\n";
            //    std::system("pause");
            //    std::system("cls");
            //    player->drawHud();
            //}
            //else if (RNG == 2 && potionRNG == 2)
            //{
            //    std::cout << "found a health potion!\n";
            //    std::cout << "-------------------------------------------------\n";
            //    player->setPotions(player->getPotions() + 1);
            //    std::system("pause");
            //    std::system("cls");
            //    player->drawHud();
            //}
            //else // if there are no goblins left in the dungeon found an exit and end the level.
            //{
            //        std::cout << "found a light!\n";
            //        endLevel();
            //}

            cmd = "nothing";
        }

        if (cmd == "wait")
        {
            std::cout << "Now waiting...\n";
            Sleep(5000);
            std::cout << "While Austin was waiting ";
                std::system("pause");
                std::system("cls");
                player->drawHud();
        }


            cmd = "nothing";
        }
    }




void Level1::setPlayer()
{
    player->setHealth(100);
    player->setPotions(0);

}

void Level1::drawEncounterHud()
{
    std::cout << "| Health: " << player->getHealth() << endl;
    std::cout << "| Health potions: " << player->getPotions() << endl;
    std::cout << "---------------------------------------------------------------\n";
}

void Level1::battle()
{
    string command;

    drawEncounterHud();
        std::cout << "Type: \n";
        std::cout << "'attack' to attack the enemy.\n";
        std::cout << "'potion' to use health potion. \n";

        while (command != "attack" &&  command != "potion")
        {
            std::cout << ">";
            getline(cin, command);
        }

        if (command == "attack")
        {
            std::cout << "Now attacking...\n";
            Sleep(2000);
            std::system("pause");
            std::system("cls");
            drawEncounterHud();

        }
        else if (command == "potion")
        {
            if (player->getPotions() > 0)
            {
                player->setPotions(player->getPotions() - 1);
                std::cout << "Now using health potion...\n";
                Sleep(2000);
                std::cout << "Austin healed for 30.\n";
                player->setHealth(player->getHealth() + 30);
                std::cout << "-------------------------------------------------\n";
                std::system("pause");
                std::system("cls");
                drawEncounterHud();
            }
            else
            {
                std::cout << "You don't have any potions left!\n";
                std::system("pause");
                std::system("cls");
                drawEncounterHud();
            }

        }

        command = "nothing";
}

void Level1::endLevel()
{
   

    playerHealth = player->getHealth();

  /*  Level2 objLevel2;
    objLevel2.loadLevel();*/
}