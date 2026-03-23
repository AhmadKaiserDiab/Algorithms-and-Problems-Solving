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

int CheckDigit(int Number, short DigitToCheck)
{
    int Remainder = 0 , FrequencyCount = 0 ; 
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        if(DigitToCheck == Remainder)
            FrequencyCount++;
    }
    return FrequencyCount;
}

int main()
{
    int Number = ReadPoisitveNumbers("Please Enter a Number: ");
    short Digit = ReadPoisitveNumbers("Please Enter a Digit To Check: ");

    cout<<"\n Digit "<<Digit<<" Frequncy Is: "
        <<CheckDigit(Number,Digit)<<" Times\n";

    return 0;
}
