#ifndef LEVEL1_H
#define LEVEL1_H

#include "Player.h"
#include "Level.h"
using namespace std;

class Level1 : public Level
{
public:
    Level1();
    void loadLevel() override;
    void printStory();





};

#endif // LEVEL1_H
