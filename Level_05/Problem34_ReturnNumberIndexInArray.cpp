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
    for(int i = 0;  i < Size ; i++ )
        Array[i] = RandomsGenerator(From,To);
}

void PrintArrayElements(int Array[], int Size){
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int CheckIndex(int Number, int Array[] , int Size){
    int Index = -1 ;
    for(int i = 0; i < Size ; i++ )
        if(Number == Array[i])
            Index = i;
    return Index;
}

void SearchForIndex(int Number , int Array[] , int Size){
    int Index = CheckIndex(Number,Array,Size);
    cout<<"\nThe Number You Are Looking For Is: "<<Number<<endl;

    if (Index != -1){
        cout<<"The Number Found At Position: "<<Index<<endl
        <<"The Number Found, It's Order: "<<Index+1<<endl;
        system("Color 2F");
    }
    else{
        cout<<"The Number Not Found At Position :-("<<endl;
        system("Color 4F");
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int Number, Size, MyArray[Size];

    FillArrayWithRandomNumbers(MyArray,Size,1,100);

    cout<<"\nArray 1 Elements: ";
    PrintArrayElements(MyArray,Size);

    Number = ReadPoisitveNumbers("\nPlease Enter A Number To Search For: ");

    SearchForIndex(Number,MyArray,Size);

    return 0;
} 
