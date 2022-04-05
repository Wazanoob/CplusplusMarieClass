#include "Probability.h"
#include <stdlib.h>
#include <iostream>

//using namespace std;
//
//void RollDices();
//
//int main()
//{
//	RollDices();
//}
//
//void RollDices() 
//{
//	srand(time(NULL));
//	int attempts = 0;
//	int faces = 6;
//	int doubleOne = 0;
//
//	while (doubleOne != 2777)
//	{
//		doubleOne = 0;
//
//		for (int i = 1; i <= 100000; ++i)
//		{
//			int count = (rand() % faces + 1) + (rand() % faces + 1);
//			if (count == 2)
//			{
//				doubleOne += 1;
//			}
//		}
//		attempts += 1;
//	}
//	cout << "PERFECT SCORE 2777 IN: " << attempts << " ATTEMPTS\n";
//}