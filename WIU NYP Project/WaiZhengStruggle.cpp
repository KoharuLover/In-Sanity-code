#include "WaiZhengStruggle.h"
#include "Story.h";

WaiZhengStruggle::WaiZhengStruggle()
{
	inputCount = 0;
	keypressed = false;
}

void WaiZhengStruggle::struggle()
{
	
	while (inputCount < 40)
	{
		if (keypressed == false) {
			if (GetAsyncKeyState(0x46) & 0x8000) {
				inputCount += 1;
				keypressed = true;
			}
		}
		else {
			keypressed = false;
			while (GetAsyncKeyState(0x46) & 0x8000) {}
		}
	}
}
