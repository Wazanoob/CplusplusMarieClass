#include "Pokemon.h"

#include <iostream>
using namespace std;

//Default constructor
Pokemon::Pokemon()
{
	mName = "Default";
	mDescription = "Default";
	mPetName = "Default";
	mMaxLifePoints = 1;
	mCurrentLifePoints = mMaxLifePoints;
}
//Constructor with Parameters
Pokemon::Pokemon(string name, string desc, int maxLifePoints)
{
	mName = name;
	mDescription = desc;
	mPetName = mName;
	mMaxLifePoints = maxLifePoints;
	mCurrentLifePoints = mMaxLifePoints;
}

//Destructor ?
Pokemon::~Pokemon()
{
	//Empty until we have complex members
}

//Return the name of the pokemon
string Pokemon::GetName()
{
	return mName;
}

//Return the description of the pokemon
string Pokemon::GetDescription()
{
	return mDescription;
}

//Return the life Max of the pokemon
int Pokemon::GetMaxLifePoints()
{
	return mMaxLifePoints;
}
//Return the current life of the pokemon
int Pokemon::GetCurrentLifePoints()
{
	return mCurrentLifePoints;
}
//Damage the current life of the pokemon
void Pokemon::Hurt(int points)
{
	cout << mPetName << " has taken " << points << " hp of damages.\n";
	//If the pokemon dont have any HP left
	if (mCurrentLifePoints - points < 0)
	{
		//The pokemon dies
		cout << mPetName << " has passed out.... You should take better care of your pokemons\n";
		mCurrentLifePoints = 0;
	}
	else //The pokemon take damage if still have HP
	{
		mCurrentLifePoints -= points;
		cout << mPetName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
//Heal the current life of the pokemon
void Pokemon::Heal(int points)
{
	cout << mPetName << " has been healed of " << points << " hp.\n";
	if (mCurrentLifePoints + points > mMaxLifePoints)
	{
		//The pokemon is full health
		cout << mPetName << "'s health is back to maximum.\n";
		mCurrentLifePoints = mMaxLifePoints;
	}
	else
	{
		mCurrentLifePoints += points;  // mCurrentLifePoints = mCurrentLifePoints + points;
		cout << mPetName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}

//Describe the pokemon
void Pokemon::DisplaySumUp()
{
	cout << mPetName << " is a " << mName << endl;
	cout << "A " << mName << " is " << mDescription << endl;
	cout << mPetName << " has " << mCurrentLifePoints << "/" << mMaxLifePoints << " hp.\n";
}
