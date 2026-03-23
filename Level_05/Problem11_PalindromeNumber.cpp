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

int ReversedDigits(int Number)
{
    int Remainder = 0 ,Number2 = 0;
    while(Number > 0) {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10  + Remainder;
    }
    return Number2;
}

void PrintResult(int Number)
{
    if(Number == ReversedDigits(Number))
        cout<<Number<<" Is A Palindrome Number";
    else
        cout<<Number<<" Is Not A Palindrome Number";
}

int main()
{

    PrintResult(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));

    return 0;
}
