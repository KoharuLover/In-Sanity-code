#include "Ccheck.h"

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