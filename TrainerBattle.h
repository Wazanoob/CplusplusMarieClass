#pragma once
#include "Trainer.h"

class TrainerBattle
{
	//Fight is between two trainers
	//the player choose their pokemons
	//AI chooses a random pokemon
	//Each turn: choose an ability of the selected pokemon
	//If the other passes out, another pokemon must be chosen
	//If the trainer has no pokemon left, they loose
	//AI chooses a random attack

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

