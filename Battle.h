#pragma once
class Battle
{
private:
	//Reference of the two pokemons fighting
	Pokemon mFirstFighter;
	Pokemon mSecondFighter;

	//whose turn it is

public:
	//Constructor
	Battle(Pokemon firstFighter, Pokemon secondFighter);

	//Destructor
	~Battle();

	//StartBattle function
	//PlayTurn Function
	//NextTurn function
	//EndBattle
};

