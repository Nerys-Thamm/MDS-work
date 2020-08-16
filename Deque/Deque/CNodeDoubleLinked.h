////////////////////////////////////////////////////////////
//========================================================//
// Bachelor of Software Engineering                       //
// Media Design School                                    //
// Auckland                                               //
// New Zealand                                            //
//--------------------------------------------------------//
// (c) 2020 Media Design School                           //
//========================================================//
//   File Name  : CNodeDoubleLinked.h                     //
//--------------------------------------------------------//
//  Description :                                         //
//                                                        //
//                                                        //
//                                                        //
//--------------------------------------------------------//
//    Author    : Nerys Thamm BSE20021                    //
//--------------------------------------------------------//
//    E-mail    : NerysThamm@gmail.com                    //
//========================================================//
////////////////////////////////////////////////////////////
#pragma once
template <class T>
class CNodeDoubleLinked
{
public:
	CNodeDoubleLinked(T _data)
	{
		pForeNode = nullptr;
		pAftNode = nullptr;
		m_data = _data;
	}
	CNodeDoubleLinked(T _data, CNodeDoubleLinked* _pForeNode, CNodeDoubleLinked* _pAftNode)
	{
		pForeNode = _pForeNode;
		pAftNode = _pAftNode;
		m_data = _data;
	}
	CNodeDoubleLinked<T>* pForeNode;
	CNodeDoubleLinked<T>* pAftNode;
	T m_data;

};

