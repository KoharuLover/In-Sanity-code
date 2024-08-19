#pragma once
class Story
{
public:
	int StartAct();
	int Act1();
	int ContAct1();
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
	void Lounge(bool result, bool KeyisFound, bool firstkeyFound);
	void Bedroom(bool result, bool KeyisFound, bool firstkeyFound);
	void Kitchen(bool result, bool KeyisFound, bool firstkeyFound);
	void DogRLGL();
	void GardRLGL();
	void NormalEnd();
};

