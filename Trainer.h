#pragma once
#include <string>
#include <vector>
#include "Pokemon.h"

class Trainer
{
private:
	//Name
	std::string mName;
	//Description
	std::string mDescription;
	//CatchPhrase
	std::string mCatchPhrase;
	//Money
	int mMoney;
	//Type
	std::string mType;
	//enum mType { men, girl };
	//Pokemons
	std::vector<Pokemon> mPokemons;
	//Pokeballs Count
	int mPokeballCount;
	//Inventory with Item Objects

public:
	//Which pokemon is Active
	int mActivePokemon;

	//Constructor
	Trainer();
	Trainer(std::string name, std::string desc, std::string catchPhrase, std::string type, std::vector<Pokemon> pokemon);
	//Destructor
	~Trainer();

	//Getters / Setters
	std::string GetName();
	std::string GetCatchPhrase();
	std::string GetType();
	int GetMoney();
	int GetPokeballCount();
	int GetPokemonCount();
	Pokemon& GetPokemon(int index);
	Pokemon& GetActivePokemon();

	//CatchPokemon
	void CatchPokemon(Pokemon pokemon);
	//ChangeActivePokemon
	void ChangePokemon(int newPokemon);
	//Display Trainer info
	void Introduce();
	//Display Pokedex
	void DisplayPokemon();

	////////Inventory Handling
	//BuyItem
	//void BuyPokemon();
	//SellItem
	//void SellPokemon();
};

