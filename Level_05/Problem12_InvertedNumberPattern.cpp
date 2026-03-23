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

void PrintInvertedNumberPattern(int Number)
{
    for ( ; Number > 0; Number--)
    {
        for (int Counter = Number; Counter > 0; Counter--)
            cout << Number;
        cout << endl;
    }
}

int main()
{
    PrintInvertedNumberPattern(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));

    return 0;
}
