#include <iostream>
#include <windows.h>
#include "coinflip.h"
#include "CTimeClock.h"

int main()
{
    coinflip door_event;
    CTimeClock timer;
    timer.Start();

    CTimeClock breathTimer;
    bool held = false;
    float timeheld = 0.0;

    while (door_event.flip()) {        
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
            std::cout << "free" << std::endl;
            break;
        }

        // break condition if player doesnt hold his breath in time
        if (timer.getElapsed() >= 5) {  // length of time can be changed
            std::cout << "caught" << std::endl;
            break;
        }
    }

    return 0;
}
