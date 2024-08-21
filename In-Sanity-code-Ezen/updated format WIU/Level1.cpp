#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
#include "Story.h"

Level1::Level1()
{

}

void Level1::loadLevel()
{
  
    printStory();


}

void Level1::printStory()
{
    Story* Act1Ptr;
    Act1Ptr = new Story;
    Act1Ptr-> NormalEnd(); //change back to startact when finished
}

