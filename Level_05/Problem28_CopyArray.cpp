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
        Array[i] = RandomsGenerator(1,100);
    }
}

void ArrayCopier(int Array1[], int Array2[], int Size){

    for(int i = 0 ; i < Size ; i++)
        Array2[i] = Array1[i];
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
    ArrayCopier(MyArray,CopyArray,Size);

    cout<<"\nArray 1 Elements: ";
    PrintArrayElements(MyArray,Size);
    cout<<"\nArray 2 Elements After Copy: ";
    PrintArrayElements(CopyArray,Size);

    return 0;
} 
