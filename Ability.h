#pragma once
#include <string>


//Describe a Pokemon ability
class Ability
{
private:
	std::string mName;
	std::string mDescription;
	int mDamage;
	int mEnergyCost;


public:
	//Constructor
	Ability();
	Ability(std::string name, std::string desc, int damages);
	Ability(std::string name, std::string desc, int damages, int energy);
	//Destructor
	~Ability();

	//Getter for attributes
	std::string GetName();
	std::string GetDescription();
	int GetDamages();
	int GetEnergyCost();
};

