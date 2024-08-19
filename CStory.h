#pragma once
#include <string>
class CStory
{
public:

	CStory();



	void StartAct();
	//void Act1();  //wayne
	//int Act2();
	//void SetPlayer();
	//void SetCreature();
	//void EncounterHUD();
	//void Act1Battle();
	//void WaitEnd();
	//void resistEnd();
	//void SurrenderEnd();
	//void meltedEnd();
	//void EscapeEnd();
	//void AttackArt();





	void gotoxy(int x, int y);
	void printDelayedText(const std::string& text);
};

