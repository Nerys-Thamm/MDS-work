////////////////////////////////////////////////////////////
//========================================================//
// Bachelor of Software Engineering                       //
// Media Design School                                    //
// Auckland                                               //
// New Zealand                                            //
//--------------------------------------------------------//
// (c) 2020 Media Design School                           //
//========================================================//
//   File Name  : CDeque.h                                //
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
#include "CNodeDoubleLinked.h"
template <class T>
class CDeque
{
private:
	CNodeDoubleLinked<T>* m_pFront;
	CNodeDoubleLinked<T>* m_pBack;
	CNodeDoubleLinked<T>* m_pTemp;
	int m_iSize;
public:
	CDeque()
	{
		m_iSize = 0;
		m_pFront = nullptr;
		m_pBack = nullptr;
		m_pTemp = nullptr;
	}
	void Enqueue_Front(T _data)
	{
		m_pTemp = new CNodeDoubleLinked<T>(_data, nullptr, m_pFront);
		if (m_pFront != nullptr)
		{
			m_pFront->pForeNode = m_pTemp;
		}
		m_pFront = m_pTemp;
		if (m_pBack == nullptr)
		{
			m_pBack = m_pTemp;
		}
		m_iSize++;

	}
	void Enqueue_Back(T _data)
	{
		m_pTemp = new CNodeDoubleLinked<T>(_data, m_pBack, nullptr);
		if (m_pBack != nullptr)
		{
			m_pBack->pAftNode = m_pTemp;
		}
		m_pBack = m_pTemp;
		if (m_pFront == nullptr)
		{
			m_pFront = m_pTemp;
		}
		m_iSize++;
	}
	T Dequeue_Front()
	{
		m_pTemp = m_pFront;
		m_pTemp->pForeNode = nullptr;
		m_pFront = m_pTemp->pAftNode;
		m_iSize--;
		return m_pTemp->m_data;
	}
	T Dequeue_Back()
	{
		m_pTemp = m_pBack;
		m_pTemp->pAftNode = nullptr;
		m_pBack = m_pTemp->pForeNode;
		m_iSize--;
		return m_pTemp->m_data;
	}
	T Peek_Front()
	{
		return m_pFront->m_data;
	}
	T Peek_Back()
	{
		return m_pBack->m_data;
	}
	bool IsEmpty()
	{
		return m_iSize <= 0;
	}
};

