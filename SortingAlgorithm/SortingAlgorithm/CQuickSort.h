#include <vector>

#pragma once
class CQuickSort
{
public:
	int Sort(int _input[], int _iLow, int _iHigh, bool _bAscending);
private:
	static void m_Swap(int& _iSwap1, int& _iSwap2);
	int m_Partition(int _input[], int _iLow, int _iHigh, bool _bAscending);
	int m_RandPivotSelection(int _input[], int _iLow, int _iHigh, bool _bAscending);
};

