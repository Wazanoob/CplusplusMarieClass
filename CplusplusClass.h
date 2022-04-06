#pragma once
#include<vector>
#include <string>
#include <iostream>

//Take the coord where life is stored to change the variable
void Damage(int& life) {
    life -= 2;
}

//Take the adress cord of life
//And then take it's reference
void DamagePointedObject(int* life) {
    *life -= 2;
}

//TileMap example 
void ShowMultiDimensionalMap()
{
    //Double dimension map
    int tileMap[5][8]{ {4, 0, 0, 1, 1, 0, 3, 0},
                        {0, 0, 1, 1, 1, 1, 1, 0},
                        {0, 2, 1, 0, 1, 1, 1, 1},
                        {3, 1, 1, 1, 1, 2, 1, 0},
                        {0, 3, 0, 1, 1, 1, 2, 0} };

    //For every coord of the multi dimension map
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 8; y++) {
            //Check the value and apply a tile
            int tile = tileMap[x][y];
            switch (tile)
            {
            case 0:
                cout << " X ";
                break;
            case 1:
                cout << " ~ ";
                break;
            case 2:
                cout << " O ";
                break;
            case 3:
                cout << " V ";
                break;
            default:
                cout << " ^ ";
                break;
            }
        }
        cout << endl;
    }

}

//Grade tab example
void ShowVector()
{
    vector<float> grades(20, 10);
    grades[5] = 12;
    grades[18] = 7;
    for (int i = 0; i < grades.size(); i++)
    {
        cout << grades[i] << " ; ";
    }
    cout << endl;
    grades.push_back(15);
    grades.push_back(12);
    grades.push_back(17);
    grades.pop_back();
    for (int i = 0; i < grades.size(); i++)
    {
        cout << grades[i] << " ; ";
    }
}

string GetLifeText(int life)
{
    return life > 5 ? "alive" : "dying";
}