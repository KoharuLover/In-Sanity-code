#pragma once
class CPosition
{
private:

	int posValue;

public:

	CPosition(int posV = 0) : posValue(posV) {}

	int getPos() const;
	void setPos(int posV);

};

