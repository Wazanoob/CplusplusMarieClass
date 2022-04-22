#include "TrainerBattle.h"
#include <iostream>

using namespace std;

TrainerBattle::TrainerBattle()
{
	mpFirstFighter = nullptr;
	mpSecondFighter = nullptr;

	mTurn = true;
}

TrainerBattle::TrainerBattle(Trainer& firstFighter, Trainer& secondFighter)
{
	mpFirstFighter = &firstFighter;
	mpSecondFighter = &secondFighter;

	mTurn = true;
}

TrainerBattle::~TrainerBattle()
{

}

void TrainerBattle::PlayTurn()
{
	Trainer* attackTrainer = mpFirstFighter;
	Trainer* defenderTrainer = mpSecondFighter;

	if (!mTurn)
	{
		attackTrainer = mpSecondFighter;
		defenderTrainer = mpFirstFighter;
	}

	//Check who is attacking or defending
	Pokemon* attacker = &mpFirstFighter->GetPokemon(mpFirstFighter->mActivePokemon);
	Pokemon* defender = &mpSecondFighter->GetPokemon(mpFirstFighter->mActivePokemon);

	if (!mTurn)
	{
		attacker = &mpSecondFighter->GetPokemon(mpFirstFighter->mActivePokemon);
		defender = &mpFirstFighter->GetPokemon(mpFirstFighter->mActivePokemon);
	}

	cout << attacker->petName << " begins this turn ! \n";

	//Let the fighter choose an attack and play it
	attacker->DisplayAbilities();
	int choice = 0;

	if (mTurn)
	{
		do
		{
			cout << "Choose an attack : \n";
			cin >> choice;
		} while (choice < 1 || choice > attacker->GetAbilityCount());
	}
	else
	{
		choice = (rand() % attacker->GetAbilityCount() + 1);
	}

	//Attack other pokemon with chose attack
	attacker->Attack(*defender, choice - 1);

	if (defender->GetCurrentLifePoints() == 0)
	{
		cout << "The battle is over for " << defender->petName << endl;

		if (defenderTrainer == mpSecondFighter)
		{
			cout << "AI Loosed a pokemon" << endl;
			ChooseAIPokemon(defenderTrainer);

			NextTurn();
		}
		else if(defenderTrainer == mpFirstFighter)
		{
			cout << "Player Loosed a pokemon" << endl;
			ChoosePokemon(defenderTrainer);

			NextTurn();
		}
	}
	else
	{
		NextTurn();
	}
}


void TrainerBattle::ChoosePokemon(Trainer* player)
{
	player->DisplayPokemon();
	int choice = -1;
	int attempts = 0;

	do
	{
		cout << "Choose a pokemon : \n";
		cin >> choice;

		attempts++;
	} while (choice < 0 || choice > player->GetPokemonCount() - 1|| player->GetPokemon(choice).GetCurrentLifePoints() <= 0 || attempts > 10);

	player->ChangePokemon(choice);

	cout << "You choosed " << player->GetPokemon(choice).GetName() << endl;
}

void TrainerBattle::ChooseAIPokemon(Trainer* AIFighter)
{
	int choice = -1;
	int attempts = 0;

	do
	{
		choice = (rand() % AIFighter->GetPokemonCount());

		attempts++;
		cout << attempts << endl;
	} while (choice > AIFighter->GetPokemonCount()|| AIFighter->GetPokemon(choice).GetCurrentLifePoints() <= 0 || attempts > 10);

	AIFighter->ChangePokemon(choice);

	cout << "AI choosed " << AIFighter->GetPokemon(choice).GetName() << endl;

}

void TrainerBattle::NextTurn()
{
	cout << " ========================\n";
	cout << " ========================\n";

	mTurn = !mTurn;
	PlayTurn();
}

void TrainerBattle::EndBattle()
{

}



void TrainerBattle::StartBattle()
{
	cout << "Battle starts between " << mpFirstFighter->GetName() << " and " << mpSecondFighter->GetName() << endl;
	mTurn = true;
	ChoosePokemon(mpFirstFighter);
	ChooseAIPokemon(mpSecondFighter);

	PlayTurn();
}
