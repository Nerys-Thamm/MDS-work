// SortingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CQuickSort.h"
#include <time.h>


using namespace std;

int main()
{
	int iArrSize;
	
	srand(time(NULL));
	CQuickSort s;

	cout << "Pwease iwnput the amownt owf dataw ewements UwU:" << endl;
	cin >> iArrSize;
	int* iArr = new int[iArrSize];
	cout << endl << "Pwease iwnput yowr dataw ewements owo: ";
	

	for (int i = 0; i < iArrSize; i++)
	{
		cin >> iArr[i];
	}
	
	
	cout << endl;
	s.Sort(iArr, 0, iArrSize-1, true);


	
	for (int i = 0; i < iArrSize; i++)
	{
		cout << iArr[i] << " ";
	}
	
	return 0x0;
}


