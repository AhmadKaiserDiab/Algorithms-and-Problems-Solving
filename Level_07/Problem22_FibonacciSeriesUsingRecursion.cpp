#include <iostream>
using namespace std;

void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
{
    int FebNumber = 0;
    if (Number > 0)
    {
        FebNumber = Prev2 + Prev1;
        Prev2 = Prev1;
        Prev1 = FebNumber;
        cout << FebNumber << " ";
        PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
    }
}

int main()
{
    PrintFibonacciUsingRecurssion(10, 0, 1);
    system("pause>0");
}

/*
#include<iostream>
using namespace std;

int ReadPoisitveNumbers(string Message);
int FibonacciSeriesUsingRecursion(int Limit);

int main(){

    FibonacciSeriesUsingRecursion(
        ReadPoisitveNumbers(
            "Enter How Many Numbers of The Series Do You Want: "));
    return 0;
}

int ReadPoisitveNumbers(string Message) {
    int x;
    do {
        cout << Message << endl;
        cin >> x;
    } while (x < 0);
    return x;
}

int FibonacciSeriesUsingRecursion(int Limit){
    int FibNumber = 0;
    cout<<endl;
    if(Limit == 1)
        return FibNumber + 1;
    else
        cout<<FibNumber + FibonacciSeriesUsingRecursion(Limit-1)<<"   ";

    cout<<endl;
    return 0;
}
*/
