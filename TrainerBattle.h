#pragma once
#include "Trainer.h"

class TrainerBattle
{
private:
	//Reference of the two trainers fighting
	Trainer* mpFirstFighter;
	Trainer* mpSecondFighter;

	//whose turn it is
	bool mTurn;

	//ChoosePokemon
	void ChoosePokemon(Trainer* fighter);
	void ChooseAIPokemon(Trainer* AIFighter);
	//PlayTurn Function
	void PlayTurn();
	//NextTurn function
	void NextTurn();
	//EndBattle
	void EndBattle();
	
public:
	//Constructor
	TrainerBattle();
	TrainerBattle(Trainer& firstFighter, Trainer& secondFighter);

	//Destructor
	~TrainerBattle();

	//StartBattle function
	void StartBattle();
};

