#pragma once
class Story
{
public:
	int StartAct();
	int Act1();
	int Act2();
	void SetPlayer();
	void SetCreature();
	void EncounterHUD();
	void Act1Battle();
	void WaitEnd();
	void resistEnd();
	void SurrenderEnd();
	void meltedEnd();
	void EscapeEnd();
	void AttackArt();
};

