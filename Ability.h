#pragma once
#include <string>
#include "Poketypes.h"

//Describe a Pokemon ability
class Ability
{
private:
	std::string mName;
	std::string mDescription;
	int mDamage;
	int mEnergyCost;
	PokeTypes mType;


public:
	//Constructor
	Ability();
	Ability(std::string name, std::string desc, int damages, PokeTypes type);
	Ability(std::string name, std::string desc, int damages, int energy);
	//Destructor
	~Ability();

	//Getter for attributes
	std::string GetName();
	std::string GetDescription();
	PokeTypes GetType();
	std::string GetStringType();
	int GetDamages();
	int GetEnergyCost();
};

