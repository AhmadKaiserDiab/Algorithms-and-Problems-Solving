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

int RandomsGenerator(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

void FillArrayWithRandomNumbers(int Array[] , int & Size , int From, int To){
    Size = ReadPoisitveNumbers("Enter Array Size: ");

    for(int i = 0;  i < Size ; i++ ){
        Array[i] = RandomsGenerator(From,To);
    }
}

void PrintArrayElements(int Array[], int Size){
    cout<<"\nArray Elements: ";
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

void ArrayCopierInReverse(int Array1[], int Array2[], int Size){
    int Counter = 0;
    for(int i = 0 ; i < Size ; i++)
        Array2[Size - i -1] = Array1[i];
}

int main()
{
    srand((unsigned)time(NULL));
    int Size, MyArray[Size] , CopyArray[Size];

    FillArrayWithRandomNumbers(MyArray,Size,1,100);
    ArrayCopierInReverse(MyArray,CopyArray,Size);

    cout<<"\nArray 1 Elements: ";
    PrintArrayElements(MyArray,Size);
    cout<<"\nArray 2 Elements After Copying Array 1 Elements In Reversed Order: ";
    PrintArrayElements(CopyArray,Size);

    return 0;
}
