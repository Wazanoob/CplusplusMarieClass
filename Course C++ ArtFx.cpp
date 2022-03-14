// Course C++ ArtFx.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

using namespace std;


//Take the coord where life is stored to change the variable
void Damage(int& life) {
	life -= 2;
}

//Take the adress cord of life
//And then take it's reference
void DamagePoitedObject(int* life) {
	*life -= 2;
}

int main()
{
	int x = 12;
	int* pX = &x;

	int life = 10;

	cout << "The value " << x << " is stored in " << &x << endl;
	cout << "The value is " << *pX << endl;

	Damage(life);
	cout << "Life left: " << life << endl;
	DamagePoitedObject(&life);
	cout << "Life left: " << life << endl;
}