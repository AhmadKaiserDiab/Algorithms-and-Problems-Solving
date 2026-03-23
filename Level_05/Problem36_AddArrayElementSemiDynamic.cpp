#include <iostream>
using namespace std;

int ReadPoisitveNumbers(string Message)
{
    int x;
    do
    {
        cout << Message << endl;
        cin >> x;
    } while (x < 0);
    return x;
}

void AddArrayElement(int Array[] , int & Size , int Number){
    Size++;
    Array[Size-1] = Number;
}

void EnterUserNumbersInArray(int Array[] , int &Size){
    bool More = true;
    int Number;
    do
    {
        Number = ReadPoisitveNumbers("\nEnter a Number: ");
        AddArrayElement(Array, Size , Number);
        cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? "; 
        cin >> More;
    } while (More);
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
}

int main()
{
    srand((unsigned)time(NULL));
    int Size = 0 , MyArray[Size];

    EnterUserNumbersInArray(MyArray , Size);

    cout<<"\nArray Length: "<<Size;
    cout<<"\nArray Elements:\n\n";
    PrintArrayElements(MyArray,Size);

    return 0;
}
