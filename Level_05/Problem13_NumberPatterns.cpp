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

void PrintNumberPatterns(int Number)
{
    for (int i = 1 ; i <= Number; i++)
        {
        for (int j = 1 ; j <= i; j++)
                cout<<i;
        cout<<endl;
        }
        
    
}

int main()
{
    PrintNumberPatterns(
        ReadPoisitveNumbers(
            "Please Enter a Number: "));

    return 0;
}
