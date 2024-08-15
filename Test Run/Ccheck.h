#pragma once
#include <iostream>
class Ccheck
{
private:
	int random;
	int findvalue;
	int keyroomid;
	int locid;
public:
	bool result();
	int roomid();
	bool findkey();
	int currentlocation(int id);
};