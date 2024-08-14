#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player
{
public:
    Player();
    int getHealth();
    int getPotions();

    void setHealth(int h);
    void setPotions(int p);

    void drawHud();

protected:
    int playerHealth;
    int playerPotions;


};

#endif // PLAYER_H