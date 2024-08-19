#include "player.h"

player::player()
{
	inputCount = 0;
	sanityDrain = 0;
	keypressed = false;
}

void player::struggle()
{
	CTimeClock timer;

	while (inputCount < 100 && sanityDrain < 100) {  // [sanityDrain < 100] the 100 can be changed to be player's current hp
		timer.Start();
		if (keypressed == false) {
			if (GetAsyncKeyState(0x46) & 0x8000) {
				inputCount += 1;
				std::cout << inputCount << std::endl;
				keypressed = true;
			}
		}
		else {
			keypressed = false;
			while (GetAsyncKeyState(0x46) & 0x8000) {}
		}
		sanityDrain += timer.getElapsed() * 5; //time * (dmg multiplier)
	}
	
	std::cout << "amt of dmg taken: " << sanityDrain;
}
