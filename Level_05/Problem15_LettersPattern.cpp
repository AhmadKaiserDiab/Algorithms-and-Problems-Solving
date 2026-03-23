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

void PrintLettersPattern(int Number)
{
    for (int i = 65; i < (65 + Number); i++)
    {
        for (int j = 65; j <= i; j++)
            cout << char(i);
        cout << endl;
    }
}

int main()
{
    PrintLettersPattern(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));

    return 0;
}
