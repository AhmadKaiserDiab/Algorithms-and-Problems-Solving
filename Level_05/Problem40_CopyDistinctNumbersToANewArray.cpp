#include <iostream>
#include <cmath>
using namespace std;

int ReadPoisitveNumbers(string Message) {
    int x;
    do {
        cout << Message << endl;
        cin >> x;
    } while (x < 0);
    return x;
}

int RandomsGenerator(int From, int To) {
    int Random = rand() % (To - From + 1) + From;
    return Random;
}

bool CheckDistinct(int Array[] , int Size , int Number ) {
    int Counter = 0;
    for (int i = 0; i < Size ; i++)
        if (Array[i] == Number)
            return false ;
    return true;
}

void FillArrayWithRandomNumbers(int Array[] , int & Size) {
    Size = ReadPoisitveNumbers("Enter Array Size: ");
    for(int i = 0;  i < Size ; i++ )
        Array[i]= RandomsGenerator(1,100);
}

void AddArrayElement(int Array[] , int & Size , int Number) {
    Size++;
    Array[Size-1] = Number;
}

void ArrayCopierOnlyDistinct(int Array1[], int Array2[], int Size , int & Size2){
    for(int i = 0 ; i < Size ; i++)
        if(CheckDistinct(Array1,i,Array1[i]))
            AddArrayElement(Array2 , Size2 ,Array1[i]);
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Size , Size2 = 0 , MyArray[Size] , CopyArray[Size];

    FillArrayWithRandomNumbers(MyArray,Size);

    cout<<"\nArray 1 Elements:\n\n";
    PrintArrayElements(MyArray,Size);

    ArrayCopierOnlyDistinct(MyArray , CopyArray , Size , Size2);

    cout<<"\n\nArray 2 Elements:\n\n";
    PrintArrayElements(CopyArray,Size2);

    return 0;
}

