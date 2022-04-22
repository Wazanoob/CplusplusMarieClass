#include "Trainer.h"
#include <string>
#include <iostream>

using namespace std;
Trainer::Trainer()
{
	mName = "Default";
	mDescription = "Default";
	mCatchPhrase = "Hello";

	mType = "Scout";

	mActivePokemon = -1;
	mMoney = 10;
	mPokeballCount = 6;
}

Trainer::Trainer(string name, string desc, string catchPhrase, string type, vector<Pokemon> pokemon)
{
	mName = name;
	mDescription = desc;
	mCatchPhrase = catchPhrase;

	mPokemons = vector<Pokemon>(pokemon);

	mType = type;

	mActivePokemon = -1;
	mMoney = 10;
	mPokeballCount = 6;
}

Trainer::~Trainer()
{
	mPokemons.~vector();
}

string Trainer::GetName()
{
	return mName;
}

string Trainer::GetCatchPhrase()
{
	return mCatchPhrase;
}

string Trainer::GetType()
{
	return mType;
}

int Trainer::GetMoney()
{
	return mMoney;
}

int Trainer::GetPokeballCount()
{
	return mPokeballCount;
}

int Trainer::GetPokemonCount()
{
	return mPokemons.size();
}

Pokemon& Trainer::GetPokemon(int index)
{
	if(index >= 0 && index < mPokemons.size())
	{
		return mPokemons[index];
	}
	else
	{
		Pokemon defaultPokemon = Pokemon();
		cerr << "You tried to access a pokemon that doesn't exist...\n";
		return defaultPokemon;
	}
}

Pokemon& Trainer::GetActivePokemon()
{
	return GetPokemon(mActivePokemon);
}

void Trainer::CatchPokemon(Pokemon pokemon)
{

}

void Trainer::ChangePokemon(int newPokemon)
{
	mActivePokemon = newPokemon;
}

void Trainer::Introduce()
{
	cout << mName << " : \"" << mCatchPhrase <<"\"" << endl;
	cout << mType << " " << mName << " wants to fight\n";
}

void Trainer::DisplayPokemon()
{
	for(int p = 0; p < mPokemons.size(); p++)
	{
		cout << "->";
		cout << " * " << p << " " << mPokemons[p].GetName() << " | "
			<< mPokemons[p].GetDescription() << " | " << mPokemons[p].GetCurrentLifePoints()
			<< "/" << mPokemons[p].GetMaxLifePoints() << " hp.\n";
	}
}
