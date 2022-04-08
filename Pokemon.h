#pragma once
#include "Ability.h"
#include <string>
#include <vector>
class Pokemon
{
	//Add all the private variables here
private:
	std::string mName;
	std::string mDescription;
	int mMaxLifePoints;
	int mCurrentLifePoints;
	//Should add Abilities later
	std::vector<Ability> mAbilities;
	//Add all the public variables and functions here

public:
	std::string petName;
	const int MAX_ABILITIES_COUNT = 4;
	Pokemon();
	Pokemon(std::string name, std::string desc, int maxLifePoints);
	//Add constructor with abilities parameter

	//The rest of the functions (Private)
	~Pokemon();

	std::string GetName();
	std::string GetDescription();
	int GetMaxLifePoints();
	int GetCurrentLifePoints();
	void Hurt(int points);
	void Heal(int points);
	void LearnAbility(Ability ability);
	void DisplayAbilities();
	//Add attack

	void DisplaySumUp();
	int GetAbilityCount();
	Ability GetAbility(int index);
	void Attack(Pokemon& target, int ability);
};