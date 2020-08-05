// SortingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CQuickSort.h"

using namespace std;

int main()
{
	vector<int> testVector = {2,5,6,3,4,7,4,7,9,1};
	for (int i = 0; i < 10; i++)
	{
		cout << testVector[i];
	}
	cout << endl;
	CQuickSort::Sort(testVector);
	for (int i = 0; i < 10; i++)
	{
		cout << testVector[i];
	}
	cin;
}


