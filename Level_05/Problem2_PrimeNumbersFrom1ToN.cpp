#include <iostream>
#include <cmath>
using namespace std;

enum enType
{
    Prime = 1,
    NotPrime = 2,
};

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

enType CheckPrime(int Number)
{

    int Half = round(Number / 2);
    for (int counter = 2; counter <= Half; counter++)
    {
        if (Number % counter == 0)
            return enType::NotPrime;
    }
    return enType::Prime;
}

void PrintResult(int Number)
{
    cout<<"Primal Numbers From 1 to "<<Number<<":\n";
    for(int Counter = 2 ; Counter<=Number; Counter++)
        if (CheckPrime(Counter) == enType::Prime )
            cout << Counter <<endl;
}

int main()
{

    PrintResult(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));

    return 0;
}
