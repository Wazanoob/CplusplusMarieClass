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

std::string Ability::GetStringType()
{
	switch (mType) 
	{
	case PokeTypes::Electric:
		return "Electric";
	case PokeTypes::Ground:
		return "Ground";
	case PokeTypes::Water:
		return "Water";
	case PokeTypes::Grass:
		return "Grass";
	case PokeTypes::Fire:
		return "Fire";
	}

	return "Default";
}

int Ability::GetDamages()
{
	return mDamage;
}

int Ability::GetEnergyCost()
{
	return mEnergyCost;
}
