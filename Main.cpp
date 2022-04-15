#include "Pokemon.h"
#include "Probability.h"
#include "CplusplusClass.h"
#include "Battle.h"
#include "Trainer.h"
#include<vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));

#pragma region Cplusplus
    //cout << "Hello World!\n";
    //int life = 10;
    //cout << "The value " << life << " is stored at memory adress : " << &life << endl;
    //Damage(life);
    //cout << life << endl;
    //DamagePointedObject(&life);
    //cout << life << endl;
    ////if life > 5 show "Alive" else show "Dying"
    //cout << "Player is " << GetLifeText(life) << endl;

    //ShowMultiDimensionalMap();
    //ShowVector();
#pragma endregion

//Pokemon
    cout << "============PIKACHU=============\n";
    Pokemon pikachu = Pokemon("Pikachu", "chunky boi", 40, PokeTypes::Electric);
    pikachu.DisplaySumUp();
    cout << "=========================\n";
    pikachu.petName = "Pika Pika";
    //pikachu.Hurt(6);
    //pikachu.Heal(12);
    //pikachu.DisplaySumUp();
    Ability thunderShock = Ability("Thunder Shock", "Goes bzzzz", 20, PokeTypes::Electric);
    Ability gnaw = Ability("Gnaw", "Gnaws", 10, PokeTypes::Ground);
    Ability cutie = Ability("Cutie Pie", "2 cute 2 be true", 10, PokeTypes::Grass);
    pikachu.LearnAbility(thunderShock);
    pikachu.LearnAbility(gnaw);
    pikachu.LearnAbility(cutie);

    Pokemon staryu = Pokemon("Staryu", "A cute starfish", 30, PokeTypes::Water);
    staryu.LearnAbility(Ability("Splash", "It's wet", 13, PokeTypes::Water));
    staryu.LearnAbility(Ability("Water Jet", "It's wetter", 15, PokeTypes::Water));

    Battle fight(pikachu, staryu);
    fight.StartBattle();

    cout << endl;

    Trainer sacha = Trainer("Sacha", "Le meilleur des dresseurs", "Attrapes moi si tu peux!", "Scout", vector<Pokemon>{pikachu, staryu});
    Trainer chasa = Trainer("Chasa", "Le pire des dresseurs", "Attrape toi si je peux!", "Scout", vector<Pokemon>{pikachu, staryu});

    sacha.Introduce();
    sacha.DisplayPokemon();
    cout << endl;

    chasa.Introduce();
    chasa.DisplayPokemon();


#pragma region Proba

    //MyRollDices();
    //MarieRollDices();

    //int sides = 6, throws = 1;

    //////////WARHAMMERGAME :)//////////
    //cout << "How many sides to the dices ?\n";
    //cin >> sides;
    //cout << "How many time do we throw ?\n";
    //cin >> throws;
    //int minimum = 0;
    //do 
    //{
    //    cout << "Minimum to touch : ";
    //    cin >> minimum;
    //} while (minimum > sides);
    //int touch = CountDicesAbove(sides, throws, minimum);
    //cout << touch << " dice made it through \n";

    //do
    //{
    //    cout << "Minimum to touch : ";
    //    cin >> minimum;
    //} while (minimum > sides);
    //int hurt = CountDicesAbove(sides, touch, minimum);
    //cout << touch << " / " << throws << " touched :" << hurt << " / " << touch << " hurted .\n";

    //float touchPercentage = (float)touch / throws;
    //float hurtPercentage = (float)hurt / touch;

    //cout << "touch ratio: " << touchPercentage << "; hurt ratio: " << hurtPercentage << endl;
#pragma endregion
}