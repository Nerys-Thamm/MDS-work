#include "CQuickSort.h"
#include <iostream>
#include <cstdlib>
#include <time.h>


void CQuickSort::m_Swap(int& _iSwap1, int& _iSwap2)
{
	int iTemp = _iSwap1;
	_iSwap1 = _iSwap2;
	_iSwap2 = iTemp;
	return;
}
int CQuickSort::m_Partition(int _input[], int _iLow, int _iHigh, bool _bAscending)
{
	int iPivotIndex = _iHigh, iCurrentIndex = _iLow;

	if (_bAscending)
	{
		for (int i = _iLow; i < _iHigh; i++)
		{
			if (_input[i] < _input[iPivotIndex])
			{
				m_Swap(_input[i], _input[iCurrentIndex]);
				iCurrentIndex++;
			}
		}
	}
	else
	{
		for (int i = _iLow; i < _iHigh; i++)
		{
			if (_input[i] > _input[iPivotIndex])
			{
				m_Swap(_input[i], _input[iCurrentIndex]);
				iCurrentIndex++;
			}
		}
	}
	m_Swap(_input[iPivotIndex], _input[iCurrentIndex]);

	return iCurrentIndex;

}
int CQuickSort::m_RandPivotSelection(int _input[], int _iLow, int _iHigh, bool _bAscending)
{
	int iPivotIndex, iRandomNumber;
	
	iRandomNumber = rand();
	
	iPivotIndex = _iLow + iRandomNumber % (_iHigh - _iLow + 1);
	m_Swap(_input[_iHigh], _input[iPivotIndex]);
	return m_Partition(_input, _iLow, _iHigh, _bAscending);
}
int CQuickSort::Sort(int _input[], int _iLow, int _iHigh, bool _bAscending)
{
	int iPivotIndex;
	if (_iLow < _iHigh)
	{
		iPivotIndex = m_RandPivotSelection(_input, _iLow, _iHigh, _bAscending);
		Sort(_input, _iLow, iPivotIndex - 1, _bAscending);
		Sort(_input, iPivotIndex + 1, _iHigh, _bAscending);
	}
	return 0;

}


