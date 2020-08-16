////////////////////////////////////////////////////////////
//========================================================//
// Bachelor of Software Engineering                       //
// Media Design School                                    //
// Auckland                                               //
// New Zealand                                            //
//--------------------------------------------------------//
// (c) 2020 Media Design School                           //
//========================================================//
//   File Name  : SortingAlgorithm.cpp                    //
//--------------------------------------------------------//
//  Description : Contains the Main function. Reads an    //
//  input text file to sort provided elements in          //
//  Ascending or Descending order using a recursive       //
//  QuickSort algorithm. See README.txt for instructions. //
//--------------------------------------------------------//
//    Author    : Nerys Thamm BSE20021                    //
//--------------------------------------------------------//
//    E-mail    : NerysThamm@gmail.com                    //
//========================================================//
////////////////////////////////////////////////////////////

#include <iostream>
#include "CQuickSort.h"
#include <time.h>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char* argv[])//Main takes parameters to allow for command line input. This is needed so the path of the input file can be specified
{

	fstream f; //Create filestream
	string sFileInput;
	string sNum = ""; //The string version of the numbers taken from the input file before they are converted to int
	bool bIsDescending; //Is the sort in descending order?
	int iArrSize; //Size of the array specified by user
	int iCurrentIndex = 0; //Current index to insert number into array to be sorted
	f.open(argv[1]); //Open the specified file

	getline(f, sFileInput);//Get the first line
	if (!(sFileInput == "0" || sFileInput == "1"))//Check if the 1st line is anything apart from 1 or 0, prints error and returns if so
	{
		cout << "Error! Line 1 of input file is Invalid. Line 1 must either be 0[Ascending] or 1[Descending]";
		cin;
		return 0;
	}
	bIsDescending = (sFileInput == "1");//Checks the value of the 1st line and uses it to set the sort to be descending or ascending
	getline(f, sFileInput);//Gets the next line
	for (size_t i = 0; i <= sFileInput.size(); i++)//for each character in the line, checks if the character is not a digit, space, or null terminator
	{
		if (((int)sFileInput[i] < 48 || (int)sFileInput[i] > 57) && sFileInput[i] != ' ' && sFileInput[i] != '\0')
		{
			cout << "Error! Line 2 must only contain Digits!";
			cin;
			return 0;
		}
	}
	
	iArrSize = stoi(sFileInput); //converts the input on line 2 from string to integer
	if (iArrSize <= 0)//Checks the validity of line 2
	{
		cout << "Error! Line 2 of input file must not be 0 and not be negative!";
		cin;
		return 0;
	}
	int* iArr = new int[iArrSize];//Creates an array of the size specified by the user
	getline(f, sFileInput);//Gets the third line in the file
	for (size_t i = 0; i <= sFileInput.size(); i++)//for each character in the line, checks if the character is not a digit, space, or null terminator
	{
		if (((int)sFileInput[i] < 48 || (int)sFileInput[i] > 57) && sFileInput[i] != ' ' && sFileInput[i] != '\0')
		{
			cout << "Error! Line 3 must only contain Digits and Spaces!";
			cin;
			return 0;
		}
	}
	for (size_t i = 0; i <= sFileInput.size(); i++)//for each character in the line
	{
		
		if (sFileInput[i] != ' ' && sFileInput[i] != '\0')//If the characyer is not a space or null
		{
			sNum += sFileInput[i];//add the character to the string that holds the number to be extracted in string form
		}
		else
		{
				iArr[iCurrentIndex] = stoi(sNum); //converts extracted number to int form and places it in appropriate index in the array to be sorted
				sNum = "";//resets string holding number to be extracted
				iCurrentIndex++;//Increments the index
		}

	}
	if (iCurrentIndex < iArrSize)//Check if the current index after number extraction is completed is smaller than the size specified by the user
	{
		cout << "Error! Line 2 specifies more elements than are provided in line 3!";
		cin;
		return 0;
	}
	else if(iCurrentIndex > iArrSize)//Check if the current index after number extraction is completed is larger than the size specified by the user
	{
		cout << "Error! Line 3 provides more elements than are specified in line 2!";
		cin;
		return 0;
	}
	f.close();//Close the file
	
	
	srand(time(NULL));//Create random seed
	CQuickSort s;//create instance of quicksort
	cout << endl;
	s.Sort(iArr, 0, iArrSize-1, !bIsDescending);//Sort the array

	ofstream output{ "Output.txt" };//Create a file

	
	for (int i = 0; i < iArrSize; i++)//write the sorted array to the file
	{
		output << iArr[i] << " ";
	}
	output.close(); //close the file
	
	return 0x0;
}


