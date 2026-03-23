#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
    void _Swap(T &Value1 , T &Value2)
    {
        T Temp = Value1;
        Value1 = Value2;
        Value2 = Temp;
    }

    protected:
        int _Size = 0;
        T * _TempArray;

    public:
        T * OriginalArray;

        clsDynamicArray(int Size = 0)
        {
            _Size = Size < 0 ? 0 : Size;
            OriginalArray = new T[Size];
        }

        ~clsDynamicArray()
        {
            delete [] OriginalArray;
        }

        bool SetItem(int Index , T Value)
        {
            if(Index < 0 || Index >= _Size)
            {
                return false;
            }
            OriginalArray[Index] = Value;
            return true;
        }
        
        bool IsEmpty()
        {
            return _Size == 0;
        }
        
        int Size()
        {
            return _Size;
        }

        void PrintList()
        {
            for(int i = 0 ; i < _Size ; i++)
            {
                cout<<OriginalArray[i]<<"  ";
            }
            cout<<"\n";
        }

        // Extensions
        void Resize(int NewSize)
        {
            if(NewSize < 0)
            {
                return ;
            }
            if(NewSize < _Size)
            {
                _TempArray = new T [NewSize];
                for (int i = 0; i < NewSize; i++)
                {
                    _TempArray[i] = OriginalArray[i];
                }
                delete [] OriginalArray;
                OriginalArray = _TempArray;
            }
            _Size = NewSize;
        }

        T GetItem(int Index)
        {
            // Simply
            return Index >= _Size || Index < 0 ? NULL : OriginalArray[Index];

            // Or
            if(Index >= _Size || Index < 0)
            {
                return NULL;
            }
            else
            {
                return OriginalArray[Index];
            }
        }

        void Reverse()
        {
            for(int i = 0 ; i < (_Size/2) ; i++ )
            {
                _Swap(OriginalArray[i],OriginalArray[Size() - i -1]);
            }
        }

        void Clear()
        {
            _Size = 0;
            _TempArray = new T[0];
            delete [] OriginalArray;
            OriginalArray = _TempArray;
        }

        bool DeleteItemAt(int index)
        {
            if (index >= _Size || index < 0)
            {
                return false;
            }

            _Size--;

            _TempArray = new T[_Size];

            // copy all before index
            for (int i = 0; i < index; i++)
            {
                _TempArray[i] = OriginalArray[i];
            }

            // copy all after index
            for (int i = index + 1; i < _Size + 1; i++)
            {
                _TempArray[i - 1] = OriginalArray[i];
            }

            delete[] OriginalArray;
            OriginalArray = _TempArray;
            return true;
        }

        bool DeleteFirstItem ()
        {
            return DeleteItemAt(0);
        }
        
        bool DeleteLastItem ()
        {
            return DeleteItemAt(Size() - 1);
        }

        int Find(T Value)
        {
            for (int i = 0; i < Size(); i++)
            {
                if(OriginalArray[i] == Value)
                {
                    return i;
                }
            }
            return -1;
        }

        bool DeleteItem(T Value)
        {
            int Index;
            while (true)
            {
                Index = Find(Value);
                if(DeleteItemAt(Index))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        bool InsertAt(int Index , T Value )
        {
            if(Index < 0 || Index > Size() )
            {
                return false;
            }
            else
            {
                _Size++;

                _TempArray = new T[Size()];

                // copy all before index
                for (int i = 0; i < Index; i++)
                {
                    _TempArray[i] = OriginalArray[i];
                }

                _TempArray[Index] = Value;

                // copy all after index
                for (int i = Index + 1; i < Size() ; i++)
                {
                    _TempArray[i] = OriginalArray[i - 1];
                }

                delete[] OriginalArray;
                OriginalArray = _TempArray;
                return true;
            }
        }


        bool InsertAtBeginning(T Value)
        {
            return InsertAt(0,Value);
        }

        bool InsertAfter(int Index , T Value )
        {
            return InsertAt(Index + 1, Value);
        }

        bool InsertAtEnd(T Value)
        {
                return InsertAfter(Size() - 1, Value);
        }

        bool InsertBefore(int Index , T Value )
        {
            if(Index == 0)
            {
                return InsertAtBeginning(Value);
            }
            else
            {
                return InsertAt(Index - 1 , Value);
            }
        }






};
