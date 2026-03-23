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

void CheckDigits(int Number, int Array[])
{
    int Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Array[Remainder]++;
    }
}

void PrintResults(int Number)
{
    int ArrayOfFrequency[10] = {0};
    
    CheckDigits(Number, ArrayOfFrequency);
    
    for (int Counter = 0; Counter < 9; Counter++)
        if (ArrayOfFrequency[Counter] != 0)
            cout << "Frequncey of " << Counter << " Is: "
                << ArrayOfFrequency[Counter] << endl;
}

int main()
{
    PrintResults(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));
    
    return 0;
}
