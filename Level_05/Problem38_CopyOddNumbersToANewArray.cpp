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

void FillArrayWithRandomNumbers(int Array[] , int & Size){
    Size = ReadPoisitveNumbers("Enter Array Size: ");
    for(int i = 0;  i < Size ; i++ )
        Array[i]= RandomsGenerator(1,100);
}

void AddArrayElement(int Array[] , int & Size , int Number){
    Size++;
    Array[Size-1] = Number;
}

void ArrayCopier(int Array1[], int Array2[], int Size , int & Size2){
    for(int i = 0 ; i < Size ; i++)
        if(Array1[i]%2 != 0)
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
    int Size , Size2 = 0 , MyArray[Size],CopyArray[Size];

    FillArrayWithRandomNumbers(MyArray,Size);

    cout<<"\nArray 1 Elements:\n";
    PrintArrayElements(MyArray,Size);

    ArrayCopier(MyArray , CopyArray , Size , Size2);

    cout<<"\n\nArray 2 Elements:\n";
    PrintArrayElements(CopyArray,Size2);


    return 0;
}
