#include "Pokemon.h"
#include "Probability.h"
#include "CplusplusClass.h"
#include "Battle.h"
#include<vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
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
    Pokemon pikachu = Pokemon("Pikachu", "chunky boi", 40);
    pikachu.DisplaySumUp();
    cout << "=========================\n";
    pikachu.petName = "Pika Pika";
    //pikachu.Hurt(6);
    //pikachu.Heal(12);
    //pikachu.DisplaySumUp();
    Ability thunderShock = Ability("Thunder Shock", "Goes bzzzz", 20);
    Ability gnaw = Ability("Gnaw", "Gnaws", 10);
    Ability cutie = Ability("Cutie Pie", "2 cute 2 be true", 10);
    pikachu.LearnAbility(thunderShock);
    pikachu.LearnAbility(gnaw);
    pikachu.LearnAbility(cutie);

    Pokemon stari = Pokemon("Stari", "A cute starfish", 30);
    stari.LearnAbility(Ability("Splash", "It's wet", 13));
    stari.LearnAbility(Ability("Water Jet", "It's wetter", 15));

    Battle fight(pikachu, stari);
    fight.StartBattle();

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