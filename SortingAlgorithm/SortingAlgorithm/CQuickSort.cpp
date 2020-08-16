////////////////////////////////////////////////////////////
//========================================================//
// Bachelor of Software Engineering                       //
// Media Design School                                    //
// Auckland                                               //
// New Zealand                                            //
//--------------------------------------------------------//
// (c) 2020 Media Design School                           //
//========================================================//
//   File Name  : CQuickSort.cpp                          //
//--------------------------------------------------------//
//  Description : Implement methods for applying Quicksort//
//  to an integer array.                                  //
//                                                        //
//                                                        //
//--------------------------------------------------------//
//    Author    : Nerys Thamm BSE20021                    //
//--------------------------------------------------------//
//    E-mail    : NerysThamm@gmail.com                    //
//========================================================//
////////////////////////////////////////////////////////////

#include "CQuickSort.h"
#include <iostream>
#include <cstdlib>
#include <time.h>


void CQuickSort::m_Swap(int& _iSwap1, int& _iSwap2)//Swaps the position of two data elements
{
	int iTemp = _iSwap1;
	_iSwap1 = _iSwap2;
	_iSwap2 = iTemp;
	return;
}
int CQuickSort::m_Partition(int _input[], int _iLow, int _iHigh, bool _bAscending)//Iterates through section of array to partition it into higher and lower than the pivot, depending on the given sort direction
{
	int iPivotIndex = _iHigh, iCurrentIndex = _iLow;//Set pivot index to be the highest of the range given and the Current index to be the lowest of the range given

	if (_bAscending)//Uses different logic based on if the sort is descending or ascending
	{
		for (int i = _iLow; i < _iHigh; i++)//Iterates through each element below the pivot
		{
			if (_input[i] < _input[iPivotIndex])//Checks if the current element is smaller than the pivot
			{
				m_Swap(_input[i], _input[iCurrentIndex]);//if so, swaps the current element with the element at iCurrentIndex, incrementing it afterwards
				iCurrentIndex++;
			}
		}
	}
	else
	{
		for (int i = _iLow; i < _iHigh; i++)//Iterates through each element below the pivot
		{
			if (_input[i] > _input[iPivotIndex])//Checks if the current element is larger than the pivot
			{
				m_Swap(_input[i], _input[iCurrentIndex]);//if so, swaps the current element with the element at iCurrentIndex, incrementing it afterwards
				iCurrentIndex++;
			}
		}
	}
	m_Swap(_input[iPivotIndex], _input[iCurrentIndex]);//Swaps the pivot back

	return iCurrentIndex;//returns the position of the pivot

}
int CQuickSort::m_RandPivotSelection(int _input[], int _iLow, int _iHigh, bool _bAscending)//Randomly selects a pivot and partitions the range of elements given according to this pivot
{
	int iPivotIndex, iRandomNumber;
	
	iRandomNumber = rand();//generates a random integer
	
	iPivotIndex = _iLow + iRandomNumber % (_iHigh - _iLow + 1);//sets pivot index to be a random number between _iHigh and _iLow, picking a random pivot within the range
	m_Swap(_input[_iHigh], _input[iPivotIndex]);//Swaps the pivot with the highest element in the range
	return m_Partition(_input, _iLow, _iHigh, _bAscending);//Partition the given range of elements according to the randomly chosen pivot
}
int CQuickSort::Sort(int _input[], int _iLow, int _iHigh, bool _bAscending)//A recursive function that uses a QuickSort algorithm to recursively partition a set of elements into those lesser and greater than a randomly chosen pivot, where each partition is partitioned itself until all elements are in ascending or descending order
{
	int iPivotIndex;
	if (_iLow < _iHigh)//if the value of the lowest element in the range is lesser than the value of the highest element in the range
	{
		iPivotIndex = m_RandPivotSelection(_input, _iLow, _iHigh, _bAscending);//Partition the range and get the position of the pivot used
		Sort(_input, _iLow, iPivotIndex - 1, _bAscending);//Sort the range of elements to the left of the pivot
		Sort(_input, iPivotIndex + 1, _iHigh, _bAscending);//Sort the range of elements to the right of the pivot
	}
	return 0;

}


