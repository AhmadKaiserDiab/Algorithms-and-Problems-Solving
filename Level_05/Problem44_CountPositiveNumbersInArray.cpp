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
        Array[i]= RandomsGenerator(-100,100);
}

int PositiveNumbersCount(int Array[] , int Size){
    int Counter = 0;
    for (int i = 0; i < Size; i++)
        if (Array[i] >= 0 )
            Counter++;
    return Counter;
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Size , MyArray[Size];

    FillArrayWithRandomNumbers(MyArray,Size);

    cout<<"\nArray Elements:\n";
    PrintArrayElements(MyArray,Size);

    cout<<"\nCount Of Positive Numbers In The Array: "
    <<PositiveNumbersCount(MyArray,Size)<<endl;

    return 0;
}
