#include "HuiEnCheck.h"
#include <cstdlib> 

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
}

int HuiEnCheck::roomid()
{
	return keyroomid = 1 + (rand() % 4);
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
	return locid = id;
}
