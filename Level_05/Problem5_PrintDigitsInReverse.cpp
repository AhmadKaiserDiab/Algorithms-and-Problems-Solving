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

void PrintResult(int Number)
{
    int Remainder = 0;
    while(Number > 0){
        Remainder = Number % 10;
        Number = Number / 10;
        cout<<Remainder<<endl;
    }
}

int main()
{
    PrintResult(ReadPoisitveNumbers("Please Enter a Number: "));

    return 0;
}
