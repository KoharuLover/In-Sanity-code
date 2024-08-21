#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "CPlayer.h"
#include "CStory.h"

Level1::Level1()
{

}

void Level1::loadLevel()
{
  
    printStory();


}

void Level1::printStory()
{
    CStory* Act1Ptr;
    Act1Ptr = new CStory;
    Act1Ptr-> StartAct();
}

