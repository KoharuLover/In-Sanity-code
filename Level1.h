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
    void startLevel();
    void setPlayer();
    void console();
    void drawEncounterHud();
    void battle();
    void endLevel();

protected:
    int playerHealth;

private:

    Player objPlayer;
    Player* player = &objPlayer;



};

#endif // LEVEL1_H
