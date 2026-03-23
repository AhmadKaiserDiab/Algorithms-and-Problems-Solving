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

void Swap(int & X , int & Y)
{
    int Temp;
    Temp = X;
    X = Y;
    Y = Temp;
}

int RandomsGenerator(int From , int To)
{
    int Random = rand() % (To - From + 1) + From;

    return Random;
}

void FillArray(int Array[] , int Size)
{
    for(int i = 0;  i < Size ; i++ )
        Array[i] = i+1;
}

void ShuffleArray(int Array[] , int Size)
{
    for (int i = 0; i < Size; i++)
        Swap(Array[RandomsGenerator(1,Size) - 1] ,
            Array[RandomsGenerator(1,Size) - 1]);
}

void PrintArrayElements(int Array[] , int Size)
{
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Size, MyArray[Size];
    Size = ReadPoisitveNumbers("Enter Array Size: ");

    FillArray(MyArray,Size);

    cout<<"\nArray Elements Before Shuffle: ";
    PrintArrayElements(MyArray,Size);

    ShuffleArray(MyArray,Size);

    cout<<"\nArray Elements After Shuffle: ";
    PrintArrayElements(MyArray,Size);

    return 0;
} 