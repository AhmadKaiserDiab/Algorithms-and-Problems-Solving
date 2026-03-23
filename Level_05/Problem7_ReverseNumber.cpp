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
    while(Number > 0){
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10  + Remainder;
    }
    return Number2;
}

/* string ReversedDigits(int Number)
{
    int Remainder = 0;
    string Reversed = "";
    while(Number > 0){
        Remainder = Number % 10;
        Number = Number / 10;
        Reversed += to_string(Remainder);
    }
    return Reversed;
} */

int main()
{

    int Number = ReadPoisitveNumbers("Please Enter a Number: ");
    cout<<"\nRevesre Of "<<Number<<" is:\n"
    <<ReversedDigits(Number)
    <<endl;

    return 0;
}
