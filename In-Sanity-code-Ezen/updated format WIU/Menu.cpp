#include <iostream>
#include <stdlib.h>
#include <string>
#include "Menu.h"
#include "Level1.h"
#include "Player.h"
#include "Level.h"
using namespace std;

Menu::Menu()
{

}

void Menu::showMenu()
{
    Level1* Level1ptr;
    Level1ptr = new Level1;
    std::system("cls");
    std::cout << "-----------------------------------------------------------------------" << endl;
    std::cout << "                                IN/SANITY" << endl;
    std::cout << "-----------------------------------------------------------------------" << endl;
    std::cout << endl;
    std::cout << "Type following number to: \n";
    std::cout << "1. Start \n";
    std::cout << "2. Credits \n";
    std::cout << "3. Exit \n";
    std::cout << "> ";
    getline(cin, menuControl);
    while (menuControl != "1" && menuControl != "2" && menuControl != "3")
    {
        std::cout << "Invalid command \n";
        getline(cin, menuControl);
    }

    if (menuControl == "1")
    {
        //start game
        
        std::system("cls");
        Level1ptr->loadLevel();
    }

    if (menuControl == "2")
    {
        showCredits();
    }

    if (menuControl == "3")
    {
        exit(0);
    }

}

void Menu::showCredits()
{
    std::system("cls");
    std::cout << "IN/SANITY\n";
    std::cout << "Written by Loo Ezen, Dylan Tarm, Wayne, Wai Zheng, Hui En \n";
    std::cout << "Software used: Visual Studio \n";
    std::cout << "Programmed in C++ \n";
    std::cout << "August 2024 \n";

    std::system("pause");
    showMenu();
}