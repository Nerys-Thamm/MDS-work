////////////////////////////////////////////////////////////
//========================================================//
// Bachelor of Software Engineering                       //
// Media Design School                                    //
// Auckland                                               //
// New Zealand                                            //
//--------------------------------------------------------//
// (c) 2020 Media Design School                           //
//========================================================//
//   File Name  : CQuickSort.h                            //
//--------------------------------------------------------//
//  Description : Defines methods for recursively         //
//  Applying a QuickSort algorithm to an integer array.   //
//                                                        //
//                                                        //
//--------------------------------------------------------//
//    Author    : Nerys Thamm BSE20021                    //
//--------------------------------------------------------//
//    E-mail    : NerysThamm@gmail.com                    //
//========================================================//
////////////////////////////////////////////////////////////

#pragma once
class CQuickSort
{
public:
	int Sort(int _input[], int _iLow, int _iHigh, bool _bAscending);//Public method that is called to sort an array
private:
	static void m_Swap(int& _iSwap1, int& _iSwap2);//Private method to swap two values
	int m_Partition(int _input[], int _iLow, int _iHigh, bool _bAscending);//Private method to partition the dataset
	int m_RandPivotSelection(int _input[], int _iLow, int _iHigh, bool _bAscending);//Private method to select a pivot randomly
};

