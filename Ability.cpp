#include "Ability.h"

using namespace std;

//Constructor
Ability::Ability() 
{
	mName = "Default";
	mDescription = "Default";
	mDamage = 0;
	mEnergyCost = -1;
}


Ability::Ability(string name, string desc, int damages, PokeTypes type) 
{
	mName = name;
	mDescription = desc;
	mDamage = damages;
	mEnergyCost = 0;
	mType = type;
}

Ability::Ability(string name, string desc, int damages, int energy) 
{
	mName = name;
	mDescription = desc;
	mDamage = damages;
	mEnergyCost = energy;
}

//Destructor
Ability::~Ability() 
{

}

//Getter for attributes
string Ability::GetName() 
{
	return mName;
}

string Ability::GetDescription() 
{
	return mDescription;
}

PokeTypes Ability::GetType()
{
	return mType;
}

int Ability::GetDamages()
{
	return mDamage;
}

int Ability::GetEnergyCost()
{
	return mEnergyCost;
}
