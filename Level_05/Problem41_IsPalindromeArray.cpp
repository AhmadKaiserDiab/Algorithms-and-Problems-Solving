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

int RandomsGenerator(int From, int To)
{
    int Random = rand() % (To - From + 1) + From;

    return Random;
}

bool CheckDistinct(int Array[] , int Size , int Number)
{
    int Counter = 0;
    for (int i = 0; i < Size ; i++)
        if (Array[i] == Number)
            return false ;
    return true;
}

void FillArrayWithInputNumbers(int Array[] , int & Size){
    Size = ReadPoisitveNumbers("Enter Array Size: ");
    for(int i = 0;  i < Size ; i++ )
        Array[i]= ReadPoisitveNumbers("Enter A Number: ");
}

void AddArrayElement(int Array[] , int & Size , int Number){
    Size++;
    Array[Size-1] = Number;
}

bool CheckArrayPalindrome(int Array[], int Size){
    bool isPalindrome;
    for (int i = 0; i < round(Size/2); i++)
        if(Array[i] == Array[Size-1-i])
            isPalindrome = true;
        else
            return false;
    return isPalindrome;
}

void PrintResult(int Array[], int Size){
    if(CheckArrayPalindrome(Array , Size))
        cout<<"The Array Is Palindrome\n";
    else
        cout<<"The Array Is Not A Palindrome\n";
}   

int main()
{
    srand((unsigned)time(NULL));
    int Size , MyArray[Size] ;

    FillArrayWithInputNumbers(MyArray,Size);

    cout<<"\nArray 1 Elements:\n\n";
    PrintResult(MyArray,Size);

    return 0;
}

