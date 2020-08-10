// SortingAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CQuickSort.h"
#include <time.h>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char* argv[])
{
	fstream f;
	string sFileInput;
	string sNum = "";
	bool bIsDescending;
	int iArrSize;
	int iCurrentIndex = 0;
	f.open(argv[1]);
	getline(f, sFileInput);
	if (!(sFileInput == "0" || sFileInput == "1"))
	{
		cout << "Error! Line 1 of input file is Invalid. Line 1 must either be 0[Ascending] or 1[Descending]";
		cin;
		return 0;
	}
	bIsDescending = (sFileInput == "1");
	getline(f, sFileInput);
	iArrSize = stoi(sFileInput);
	if (iArrSize <= 0)
	{
		cout << "Error! Line 2 of input file must not be 0 and not be negative!";
		cin;
		return 0;
	}
	int* iArr = new int[iArrSize];
	getline(f, sFileInput);
	for (size_t i = 0; i <= sFileInput.size(); i++)
	{
		
		if (sFileInput[i] != ' ' && sFileInput[i] != '\0')
		{
			sNum += sFileInput[i];
		}
		else
		{
			
			
				
				iArr[iCurrentIndex] = stoi(sNum);
				sNum = "";
				iCurrentIndex++;
			

		}

	}
	if (iCurrentIndex < iArrSize)
	{
		cout << "Error! Line 2 specifies more elements than are provided in line 3!";
		cin;
		return 0;
	}
	else if(iCurrentIndex > iArrSize)
	{
		cout << "Error! Line 3 provides more elements than are specified in line 2!";
		cin;
		return 0;
	}
	f.close();
	
	
	srand(time(NULL));
	CQuickSort s;

	//cout << "Pwease iwnput the amownt owf dataw ewements UwU:" << endl;
	//cin >> iArrSize;
	
	//cout << endl << "Pwease iwnput yowr dataw ewements owo: ";
	

	//for (int i = 0; i < iArrSize; i++)
	//{
	//	cin >> iArr[i];
	//}
	
	
	cout << endl;
	s.Sort(iArr, 0, iArrSize-1, !bIsDescending);


	
	for (int i = 0; i < iArrSize; i++)
	{
		cout << iArr[i] << " ";
	}
	
	return 0x0;
}


