#include "HuiEnCheck.h"
#include <cstdlib> 
#include <ctime>

bool HuiEnCheck::keyPositionGenerated = false;
int HuiEnCheck::keyroomid = -1;

HuiEnCheck::HuiEnCheck()
{
	if (!keyPositionGenerated) {
		srand(static_cast<unsigned>(time(0))); // Seed the random number generator
		keyroomid = 1 + (rand() % 3); // Generate a random room ID (1 to 3)
		keyPositionGenerated = true;
	}
}

bool HuiEnCheck::result()
{
	random = 1 + (rand() % 3);
	findvalue = 1 + (rand() % 5);

	if (random == 1 || random == 2 && findvalue != 2)
	{
		return false;
	}
	else if (random == 2 && findvalue == 2)
	{
		return true;
	}
	return false;
}

int HuiEnCheck::roomid()
{
	srand(time(0));
	return keyroomid = 1 + (rand() % 3);
}

bool HuiEnCheck::findkey()
{
	if (locid == keyroomid)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int HuiEnCheck::currentlocation(int id)
{
	locid = id;
	return locid;
}

