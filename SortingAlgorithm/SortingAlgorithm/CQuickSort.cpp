#include "CQuickSort.h"
#include <iostream>


void CQuickSort::Swap(int& _iSwap1, int& _iSwap2)
{
	int iTemp = _iSwap1;
	_iSwap1 = _iSwap2;
	_iSwap2 = iTemp;
	return;
}
void CQuickSort::Sort(std::vector<int>& _input)
{
	int iSize = static_cast<int>(_input.size());
	std::cout << "a";
	if (iSize <= 1) { return; }
	if (iSize == 2) 
	{
		if (_input[0] > _input[1])
		{
			Swap(_input[0], _input[1]);
		}
		return;
	}
	int iUpCounter, iDownCounter;
	bool bHasSwapped = false;
	Swap(_input[0], _input[ceil(iSize / 2)-1]);
	std::cout << "b";
	int iUpIndex = 0, iDownIndex = iSize;
	while (iUpIndex < iDownIndex)
	{

		for (int i = 1; i < iSize; i++)
		{
			if (_input[i] > _input[0])
			{
				iUpCounter = _input[i];
				break;
			}
		}

		Swap(_input[iUpIndex], _input[iDownIndex++]);
		std::cout << "e";
		
	} 
	Swap(_input[iDownIndex], _input[0]);

	std::vector<int> LowerVector, UpperVector;

	for (int i = 0; i < iDownIndex; i++)
	{
		LowerVector.push_back(_input[i]);
	}
	for (int i = iSize; i > iDownIndex; i--)
	{
		UpperVector.push_back(_input[i-1]);
	}

	Sort(LowerVector);
	Sort(UpperVector);
	for (int i = 0; i < iDownIndex; i++)
	{
		_input[i] = LowerVector[i];
	}
	for (int i = iSize-1; i > iDownIndex; i--)
	{
		_input[i] = UpperVector[i];
	}
	return;

}


