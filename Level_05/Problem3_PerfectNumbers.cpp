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

bool CheckPerfect(int Number)
{
    int Sum = 0;

    for (int Counter = 1; Counter < Number; Counter++)
    {
        if (Number % Counter == 0)
            Sum+=Counter;
    }

    return Sum == Number;
    }

void PrintResult(int Number)
{
    
    if(CheckPerfect(Number))
        cout << Number << " Is a Perfect Number\n";
    else
        cout << Number << " Is Not a Perfect Number\n";
        
}

int main()
{
    PrintResult(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));

    return 0;
}
