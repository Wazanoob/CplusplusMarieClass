#pragma once
#include "Pokemon.h"

class Battle
{
private:
	//Reference of the two pokemons fighting
	Pokemon* mpFirstFighter;
	Pokemon* mpSecondFighter;

	//whose turn it is
	bool mTurn;

	//PlayTurn Function
	void PlayTurn();
	//NextTurn function
	void NextTurn();
	//EndBattle
	void EndBattle();

public:
	//Constructor
	Battle();
	Battle(Pokemon& firstFighter, Pokemon& secondFighter);

	//Destructor
	~Battle();

	//StartBattle function
	void StartBattle();
};

