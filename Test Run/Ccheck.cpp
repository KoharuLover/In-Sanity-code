#include "Ccheck.h"
#include <cstdlib> 
bool Ccheck:: result()
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

int Ccheck::roomid()
{
	return keyroomid = 1+(rand() % 4);
}
int Ccheck::currentlocation(int id)
{
	return locid=id;
}

bool Ccheck::findkey()
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
