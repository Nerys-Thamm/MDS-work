#include "CQuickSort.h"


using namespace std;
void CQuickSort::Sort(vector<int>& _input)
{
	int iSize = _input.size;
	if (iSize == 1) { return; }
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
	Swap(_input[0], _input[ceil(iSize / 2)]);
	int iUpIndex = 1, iDownIndex = iSize;
	do
	{
		iUpIndex = 1;
		iDownIndex = iSize;
		do
		{
			iUpCounter = _input[iUpIndex];
		} while (!(iUpCounter++ > _input[0]));
		do
		{
			iDownCounter = _input[iDownIndex];
		} while (!(iUpCounter-- < _input[0]));

		Swap(_input[iUpIndex], _input[iDownIndex]);
		
	} while (iUpIndex < iDownIndex);
	Swap(_input[iDownIndex], _input[0]);

	vector<int> LowerVector, UpperVector;

	for (int i = 0; i < iDownIndex; i++)
	{
		LowerVector.push_back(_input[i]);
	}
	for (int i = iSize; i > iDownIndex; i--)
	{
		UpperVector.push_back(_input[i]);
	}
	Sort(LowerVector);
	Sort(UpperVector);
	for (int i = 0; i < iDownIndex; i++)
	{
		_input[i] = LowerVector[i];
	}
	for (int i = iSize; i > iDownIndex; i--)
	{
		_input[i] = UpperVector[i];
	}
	return;

}

void CQuickSort::Swap(int& _iSwap1, int& _iSwap2)
{
	int iTemp = _iSwap1;
	_iSwap1 = _iSwap2;
	_iSwap2 = iTemp;
}