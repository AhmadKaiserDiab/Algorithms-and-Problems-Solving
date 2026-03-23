#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
    protected:
        //* We Used "Composition" insted of "Inheritance" beacuse 
        //* we don't need all the methods inside the class
        clsDblLinkedList <T> _MyList;

    public:

        void Push(T Value)
        {
            _MyList.InsertAtEnd(Value);
        }

        void Pop()
        {
            _MyList.DeleteFirstNode();
        }

        void Print()
        {
            _MyList.PrintList();
        }

        int Size()
        {
            return _MyList.Size();
        }

        bool IsEmpty()
        {
            return _MyList.IsEmpty();
        }

        T Front()
        {
            return _MyList.GetItem(0);
        }

        T Back()
        {
            return _MyList.GetItem(Size() - 1);
        }

        //? Extensions
        //////////////////////////////////

        T GetItem(int Index)
        {
            return _MyList.GetItem(Index);
        }

        void Reverse()
        {
            _MyList.Reverse();
        }

        bool UpdateItem(int Index , T NewValue)
        {
            return _MyList.UpdateItem(Index , NewValue);
        }

        void InsertAfter(int Index , T NewValue) 
        {
            _MyList.InsertAfter(Index,NewValue);
        }

        void InsertAtFront(T Value)
        {
            _MyList.InsertAtBeginning(Value);
        }

        void InsertAtBack(T Value)
        {
            _MyList.InsertAtEnd(Value);
        }

        void Clear()
        {
            _MyList.Clear();
        }

};
