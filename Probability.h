#pragma once
#include<vector>
#include <string>
#include <iostream>

using namespace std;

int ThrowDice(int sides) {
    return (rand() % sides) + 1;
    //The rest of the division of rand by sides
}

int SumDices(int throws, int sides) {
    int sum = 0;
    for (int i = 0; i < throws; i++)
    {
        int dice = ThrowDice(sides);
        //cout << dice << endl;
        sum += dice;
    }

    return sum;
}

int CountDicesAbove(int sides, int throws, int minimum) {
    int count = 0;
    for (int t = 0; t < throws; t++)
    {
        if (ThrowDice(sides) >= minimum)
            count++;
    }

    return count;
}

void MyRollDices()
{
    int attempts = 0;
    int faces = 6;
    int doubleOne = 0;

    while (doubleOne != 2777)
    {
        doubleOne = 0;

        for (int i = 1; i <= 100000; ++i)
        {
            int count = (rand() % faces + 1) + (rand() % faces + 1);
            if (count == 2)
            {
                doubleOne += 1;
            }
        }
        attempts += 1;
    }
    cout << "PERFECT SCORE 2777 IN: " << attempts << " ATTEMPTS\n";
}

void MarieRollDices()
{
    int sides = 6, throws = 1;
    cout << "How many sides to the dices ?\n";
    cin >> sides;
    cout << "How many time do we throw ?\n";
    cin >> throws;
    int sum = 0;
    for (int i = 0; i < throws; i++)
    {
        sum += SumDices(throws, sides);
    }
    cout << "Launching" << throws << " times " << sides << "-sided dices : " << sum << endl;
    cout << "The avarage of a cide throw is" << (sum / throws) << endl;
}
