#include <iostream>
#include <cmath>
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

bool CheckPrime(int Number)
{
    int Half = round(Number / 2);
    for (int counter = 2; counter <= Half; counter++)
    {
        if (Number % counter == 0)
            return false ;
    }
    return true;
}

int RandomsGenerator(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;

    return Random;
}

void FillArrayWithRandomNumbers(int Array[] , int & Size , int From, int To){
    Size = ReadPoisitveNumbers("Enter Array Size: ");

    for(int i = 0;  i < Size ; i++ )
        Array[i] = RandomsGenerator(From,To);
}

void ArrayCopierOnlyPrime(int Array1[], int Array2[], int & Size){
    int Counter = 0;
    for(int i = 0 ; i < Size ; i++)
        if(CheckPrime(Array1[i]))
            Array2[Counter++] = Array1[i];
    Size = Counter;
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Size, MyArray[Size] , CopyArray[Size];

    FillArrayWithRandomNumbers(MyArray,Size,1,100);
    
    cout<<"\nArray 1 Elements: ";
    PrintArrayElements(MyArray,Size);

    ArrayCopierOnlyPrime(MyArray,CopyArray,Size);

    cout<<"\nPrime Numbers In Array 2: ";
    PrintArrayElements(CopyArray,Size);

    return 0;
} 
