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

    for(int i = 0;  i < Size ; i++ )
        Array[i] = RandomsGenerator(1,100);
}

void SumOf2Arrays(int Array1[], int Array2[] ,
                    int Array3[] , int Size ){
    for (int i = 0; i < Size; i++)
        Array3[i] = Array1[i] + Array2[i];    
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    srand((unsigned)time(NULL));
    int Size, MyArray1[Size], MyArray2[Size], MyArray3[Size];
    Size = ReadPoisitveNumbers("Enter Array Size: ");


    FillArrayWithRandomNumbers(MyArray1,Size,1,100);
    FillArrayWithRandomNumbers(MyArray2,Size,1,100);
    SumOf2Arrays(MyArray1,MyArray2,MyArray3,Size);
    

    cout<<"\nArray 1 Elements: ";
    PrintArrayElements(MyArray1,Size);
    
    cout<<"\nArray 2 Elements: ";
    PrintArrayElements(MyArray2,Size);
    
    cout<<"\nSum Of Array1 And Array2 Elements: ";
    PrintArrayElements(MyArray3,Size);

    return 0;
} 
