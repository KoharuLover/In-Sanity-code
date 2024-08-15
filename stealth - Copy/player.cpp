#include "player.h"

player::player()
{
	stealthValue = 2;
	hideprompt = "";
	enemyAlerted = true;
}

void player::setStealth(int s)
{
    stealthValue += s;;
}

int player::getStealth()
{
    return stealthValue;
}

void player::hideAttempt()
{
    CTimeClock timer;
    timer.Start();
    std::cout << "key 'hide' to hide from enemy : ";
    std::cin >> hideprompt;
    if (hideprompt != "hide") {
        std::cout << "caught" << std::endl;
    }
    else if (timer.getElapsed() >= 5) {
        std::cout << timer.getElapsed() << std::endl;
        std::cout << "you took too long to make a decision" << std::endl;
    }
    else {
        bool held = false;
        double timeheld = 0.0f;
        std::cout << "hold space down for 5s to avoid being found" << std::endl;

        while (enemyAlerted) {
            // Check if the space bar is being pressed
            if (GetAsyncKeyState(VK_SPACE)) {
                held = true;
                std::cout << "Space bar is being held down." << std::endl;
                timer.Start();
                Sleep(500);  // connsole update interval (in milliseconds)
                timeheld += timer.getElapsed();
                std::cout << timer.getElapsed() << std::endl;
                std::cout << "timeheld: " << timeheld << std::endl;

            }

            // break condition after spacebar is held and let go of(enemy catches player)
            if (held && timer.getElapsed() >= 1) {
                std::cout << "CAUGHT" << std::endl;
                break;
            }
            // break condition after spacebar is held for 5s(successfully avoided enemy)
            else if (held && timeheld >= 5) {
                std::cout << "safe" << std::endl;
                break;
            }

            // break condition if player doesnt hold his breath in time
            if (timer.getElapsed() >= 5) {  // length of time can be changed
                std::cout << "caught" << std::endl;
                break;
            }
        }
    }
}
