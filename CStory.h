#pragma once
#include <string>
class CStory
{
private:

	


public:

	CStory();


	void StartScreen();
	void StartAct();
	void Act1();  //wayne

	//int TimeRanOut();

	//void ignoreInputUntilNewline();

	//void TimeMonitor(WaiZhengClock* clockPtr);
	//int Act2();
	//void SetPlayer();
	//void SetCreature();
	//void EncounterHUD();
	//void Act1Battle();
	void WaitEnd();
	//void resistEnd();
	//void SurrenderEnd();
	//void meltedEnd();
	//void EscapeEnd();
	//void AttackArt();
    //bool timeExpired(WaiZhengClock* clockPtr);*/






	void gotoxy(int x, int y);
	void printDelayedText(const std::string& text);
	void hideCursor();
};

