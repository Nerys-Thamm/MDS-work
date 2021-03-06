////////////////////////////////////////////////////////////
//========================================================//
// Bachelor of Software Engineering                       //
// Media Design School                                    //
// Auckland                                               //
// New Zealand                                            //
//--------------------------------------------------------//
// (c) 2020 Media Design School                           //
//========================================================//
//   File Name  : Deque.cpp                               //
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

#include <iostream>
#include "CDeque.h"
using namespace std;

int main()
{
    CDeque<int> deque;
    deque.Enqueue_Back(1);
    deque.Enqueue_Front(2);
    deque.Enqueue_Back(3);
    deque.Enqueue_Front(4);

    cout << deque.Dequeue_Front();
    cout << deque.Dequeue_Front();
    cout << deque.Dequeue_Front();
    cout << deque.Dequeue_Front();
    cout << deque.IsEmpty();
}

