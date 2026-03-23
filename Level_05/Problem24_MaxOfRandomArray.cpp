#include<iostream>
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

int MaxOfRandomArray(int Array[], int Size)
{
    int Max = 0;
    for (int i = 0; i < Size; i++)
        if (Max <= Array[i])
            Max = Array[i];
    return Max;
}

void PrintArrayElements(int Array[], int Size){
    cout<<"\nArray Elements: ";
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int Size, MyArray[Size];

    FillArrayWithRandomNumbers(MyArray, Size, 1, 100);
    PrintArrayElements(MyArray, Size);

    cout << "Max Number is: " << MaxOfRandomArray(MyArray, Size) << endl;

    return 0;
}
