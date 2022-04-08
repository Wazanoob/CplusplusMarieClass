#include "Pokemon.h"

#include <iostream>
using namespace std;

//Default constructor
Pokemon::Pokemon()
{
	mName = "Default";
	mDescription = "Default";
	petName = "Default";
	mMaxLifePoints = 1;
	mCurrentLifePoints = mMaxLifePoints;
}
//Constructor with Parameters
Pokemon::Pokemon(string name, string desc, int maxLifePoints)
{
	mName = name;
	mDescription = desc;
	petName = mName;
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
	cout << petName << " has taken " << points << " hp of damages.\n";
	//If the pokemon dont have any HP left
	if (mCurrentLifePoints - points < 0)
	{
		//The pokemon dies
		cout << petName << " has passed out.... You should take better care of your pokemons\n";
		mCurrentLifePoints = 0;
	}
	else //The pokemon take damage if still have HP
	{
		mCurrentLifePoints -= points;
		cout << petName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}
//Heal the current life of the pokemon
void Pokemon::Heal(int points)
{
	cout << petName << " has been healed of " << points << " hp.\n";
	if (mCurrentLifePoints + points > mMaxLifePoints)
	{
		//The pokemon is full health
		cout << petName << "'s health is back to maximum.\n";
		mCurrentLifePoints = mMaxLifePoints;
	}
	else
	{
		mCurrentLifePoints += points;  // mCurrentLifePoints = mCurrentLifePoints + points;
		cout << petName << " now has " << mCurrentLifePoints << "/" << mMaxLifePoints << endl;
	}
}

void Pokemon::LearnAbility(Ability ability)
{
	cout << "Trying to learn " << ability.GetName() << endl;

	if (mAbilities.size() < MAX_ABILITIES_COUNT)
	{
		//Add ability
		mAbilities.push_back(ability);
		cout << mName << " learned : " << ability.GetName() << endl;
	}
	else
	{
		cout << mName << " Already knows " << MAX_ABILITIES_COUNT << " abilities\n";
		//TODO choose ability to replace
		int choice = 0;

		do 
		{
			cout << "Which one do you want to replace ?\n";
			DisplayAbilities();
			cin >> choice;
		} while (choice <= 0 || choice > MAX_ABILITIES_COUNT);

		mAbilities[choice - 1] = ability;
		cout << "Ability was replaced with success. \n";
		cout << "New Abilities are : \n";
	}
	DisplayAbilities();
}

void Pokemon::DisplayAbilities() 
{
	//cout << petName << " knows the following abilities :\n";
	for (int a = 0; a < mAbilities.size(); a++)
	{
		cout << "\t*" << (a + 1 ) 
			<< " : " << mAbilities[a].GetName() 
			<< " | " << mAbilities[a].GetDescription() 
			<< " | dmg : " << mAbilities[a].GetDamages() << "hp.\n";
	}
}

int Pokemon::GetAbilityCount() 
{
	return mAbilities.size();
}

Ability Pokemon::GetAbility(int index)
{
	if (index > 0 && index < mAbilities.size())
	{
		return mAbilities[index];
	}
	else 
	{
		return Ability();
	}
}

void Pokemon::Attack(Pokemon& target, int ability)
{
	cout << petName << " attacks " << target.petName << " with " << mAbilities[ability].GetName() << endl;
	target.Hurt(mAbilities[ability].GetDamages());
}

//Describe the pokemon
void Pokemon::DisplaySumUp()
{
	cout << petName << " is a " << mName << endl;
	cout << "A " << mName << " is " << mDescription << endl;
	cout << petName << " has " << mCurrentLifePoints << "/" << mMaxLifePoints << " hp.\n";
}
