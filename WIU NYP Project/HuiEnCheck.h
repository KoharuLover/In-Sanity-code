#pragma once
#include <iostream>
class HuiEnCheck
{
private:
	int random;
	int findvalue;
	static bool keyPositionGenerated;
	static int keyroomid;
	int locid;
public:
	HuiEnCheck();
	bool result();
	int roomid();
	bool findkey();
	int currentlocation(int id);
};

