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

void PrintInvertedLettersPattern(int Number)
{
    for ( ; Number > 0; Number--)
    {
        for (int Counter = Number; Counter > 0; Counter--)
            cout << char(Number+64);
        cout << endl;
    }
}

//           OR

// void PrintInvertedLettersPattern(int Number)
// {
//     for (int i = Number + 65 - 1 ;  i >= 65 ; i--)
//     {
//         for (int j = 65; j <= i; j++)
//             cout << char(i);
//         cout << endl;
//     }
// }

int main()
{
    PrintInvertedLettersPattern(
        ReadPoisitveNumbers("Please Enter a Number: "));

    return 0;
}
