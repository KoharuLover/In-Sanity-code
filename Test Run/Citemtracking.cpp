#include "Citemtracking.h"

int track::potion()
{
	return potioncount++;
}
int track::key()
{
	return keycount++;
}

bool track::keystate()
{
	return !keyfound;
}