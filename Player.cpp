#include <iostream>
#include <stdlib.h>
#include <string>
#include "Level1.h"
#include "Menu.h"
#include "Player.h"
using namespace std;

Player::Player()
{

}

int Player::getHealth() { return playerHealth; }
int Player::getPotions() { return playerPotions; }

void Player::setHealth(int h) { playerHealth = h; }
void Player::setPotions(int p) { playerPotions = p; }


void Player::drawHud()
{
    cout << "| Health: " << getHealth() << "            | Health: " << endl;
    cout << "| Health potions: " << getPotions() << "      |" << endl;
    cout << "---------------------------------------------------------------\n";
}