#include "coinflip.h"

coinflip::coinflip()
{
	srand(time(0));
	rng = rand() % 2; // 0: lost(alerted), 1: won(not alerted)
}

bool coinflip::flip()
{
	if (rng == 0) {
		return true;
	}
	else if (rng == 1) {
		return false;
	}
}
