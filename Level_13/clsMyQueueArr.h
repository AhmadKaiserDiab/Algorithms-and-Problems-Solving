#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
    protected:
        //* Building Queue Using "Dynamic Array" Principle
        //* We Used "Composition" insted of "Inheritance" beacuse 
        //* we don't need all the methods inside the class
        clsDynamicArray <T> _MyArray;

    public:

        void Push(T Value)
        {
            _MyArray.InsertAtEnd(Value);
        }

        void Pop()
        {
            _MyArray.DeleteFirstItem();
        }

        void Print()
        {
            _MyArray.PrintList();
        }

        int Size()
        {
            return _MyArray.Size();
        }

        bool IsEmpty()
        {
            return _MyArray.IsEmpty();
        }

        T Front()
        {
            return _MyArray.GetItem(0);
        }

        T Back()
        {
            return _MyArray.GetItem(Size() - 1);
        }

        //? Extensions
        //////////////////////////////////

        T GetItem(int Index)
        {
            return _MyArray.GetItem(Index);
        }

        void Reverse()
        {
            _MyArray.Reverse();
        }

        bool UpdateItem(int Index , T NewValue)
        {
            return _MyArray.SetItem(Index , NewValue);
        }

        void InsertAfter(int Index , T NewValue) 
        {
            _MyArray.InsertAfter(Index,NewValue);
        }

        void InsertAtFront(T Value)
        {
            _MyArray.InsertAtBeginning(Value);
        }

        void InsertAtBack(T Value)
        {
            _MyArray.InsertAtEnd(Value);
        }

        void Clear()
        {
            _MyArray.Clear();
        }

};
