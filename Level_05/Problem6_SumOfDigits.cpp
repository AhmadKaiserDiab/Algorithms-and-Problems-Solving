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

int SumOfDigits(int Number)
{
    int Remainder = 0;
    int Sum = 0;
    while(Number > 0){
        Remainder = Number % 10;
        Number = Number / 10;
        Sum+=Remainder;
    }
    return Sum;
}

int main()
{

    int Number = ReadPoisitveNumbers("Please Enter a Number: ");
    cout<<"\nSum Of "<<Number<<" is:\n"
    <<SumOfDigits(Number)
    <<endl;

    return 0;
}
