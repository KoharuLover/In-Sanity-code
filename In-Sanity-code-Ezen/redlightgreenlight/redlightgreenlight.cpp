// redlightgreenlight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include "slowtext.h"

void updateRandomNumbers(std::set<int>& randomNumbers, int min, int max, int growltrigger) {
    randomNumbers.clear();
    while (randomNumbers.size() < growltrigger) {
        int num = min + (rand() % (max - min + 1));
        randomNumbers.insert(num);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int growltrigger = 4;
    const int min = 1;
    const int max = 10;
    std::string playermove;
    int playerposition = 0;
    bool waking = false;
    bool awakedeath = false;


    std::set<int> randomNumbers;
   
    updateRandomNumbers(randomNumbers, min, max, growltrigger);

   

    while (true) {

        if (randomNumbers.find(playerposition) != randomNumbers.end()) {
            std::cout << "\nthe dog begins to show an expression of what seems like a growl. \nYou see a frown form as it begins to twitch and convulse \n";
            waking = true;
        }

        std::cout << "\n'move' or 'stay'\n\n";

        std::cin >> playermove;

        clearScreen();

        if (playermove == "move") {
            if (waking)
            {

                awakedeath = true;

            }
            if (awakedeath) {
                std::cout << "The 'dog' awakens, it snarls before leaping onto you. You try to dodge it, but it seems as though you are too slow. \nIt pounces on top of you, drooling all over you. Its acidic saliva-like substance melting into you. \nDarkness envelops you once more. Close. Not close enough.\n";
                return 0;
            }
            playerposition++;
            
        }

        waking = false;

        if (waking = true && playermove == "stay") {
            waking = false;

            std::cout << "\nits expression softens again. its breathing slows.\nit looks rather at peace somehow, even with its grotesque features.\n";
            updateRandomNumbers(randomNumbers, min, max, growltrigger);
          
        }

        if (playerposition > max) {

            std::cout << "You grabbed the key after what felt like an eternity and slowly made your way back" << std::endl;
            break;

            clearScreen();
        }
    }
 
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
