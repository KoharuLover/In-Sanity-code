#pragma once
#include <stdlib.h>
#include <iostream>
#include <time.h> 
class coinflip
{
private:
	int rng;

public:
	coinflip();
	bool flip();
};

