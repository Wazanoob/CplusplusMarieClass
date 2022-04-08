#include "Battle.h"
#include <iostream>

using namespace std;

//bool mTurn = false;

Battle::Battle()
{
	mpFirstFighter = nullptr;
	mpSecondFighter = nullptr;
}

Battle::Battle(Pokemon& firstFighter, Pokemon& secondFighter)
{
	mpFirstFighter = &firstFighter;
	mpSecondFighter = &secondFighter;
}

void Battle::PlayTurn()
{
	//Check who is attacking or defending
	Pokemon* attacker= mpFirstFighter;
	Pokemon* defender = mpSecondFighter;

	if (!mTurn)
	{
		attacker = mpSecondFighter;
		defender = mpFirstFighter;
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
		cout << "Congrats to " << attacker->petName << endl;
		EndBattle();
	}
	else
	{
		NextTurn();
	}


}

void Battle::NextTurn()
{
	cout << " ========================\n";
	cout << mpFirstFighter->petName << " : " << mpFirstFighter->GetCurrentLifePoints() << endl;
	cout << mpSecondFighter->petName << " : " << mpSecondFighter->GetCurrentLifePoints() << endl;
	cout << " ========================\n";

	mTurn = !mTurn;
	PlayTurn();
}

void Battle::EndBattle()
{
}

Battle::~Battle()
{

}

void Battle::StartBattle()
{
	cout << "Battle starts between " << mpFirstFighter->petName << " and " << mpSecondFighter->petName << endl;
	mTurn = true;
	PlayTurn();
}
