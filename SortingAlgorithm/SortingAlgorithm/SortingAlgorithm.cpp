// SortingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CQuickSort.h"
#include <time.h>


using namespace std;

int main()
{
	srand(time(NULL));
	CQuickSort s;
	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	s.Sort(arr, 0, 9, false);


	
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i];
	}
	
	return 0x0;
}


