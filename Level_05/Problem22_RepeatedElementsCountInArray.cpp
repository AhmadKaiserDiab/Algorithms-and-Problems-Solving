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

void FillArray(int Array[] , int & Size){
    Size = ReadPoisitveNumbers("Enter Array Size: ");

    cout<<"Enter Array Elements:\n";
    
    for(int i = 0;  i < Size ; i++ ){
        cout<<"Elements["<<i+1<<"]: ";
        cin>>Array[i];
        cout<<endl;
    }
}

int CheckFrequency(int  Array[] , int Size ,int Element) {
    int Counter = 0;
    for (int i = 0; i < Size ; i++)
        if (Element == Array[i])
            Counter++;
    return Counter;
}

void PrintArrayElements(int Array[], int Size){
    cout<<"\nOriginal Array: ";
    for(int i = 0;  i < Size ; i++ )
        cout<<Array[i]<<" ";
    cout<<endl;
}

int main()
{
    int Size , MyArray[Size];

    FillArray(MyArray , Size);

    int Number = ReadPoisitveNumbers(
        "Enter The Number You Want To Check");

    PrintArrayElements(MyArray,Size);

    cout<<"\n"<<Number<<" Is Repeated "
        <<CheckFrequency(MyArray,Size,Number)
        <<" Times\n";

    return 0;
}
