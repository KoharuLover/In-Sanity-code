#pragma once
class WaynePos
{
private:

	int posValue;

public:

	WaynePos(int posV = 0) : posValue(posV) {}

	int getPos() const;
	void setPos(int posV);

};

