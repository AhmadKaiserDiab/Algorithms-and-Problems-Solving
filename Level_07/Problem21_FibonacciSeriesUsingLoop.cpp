#include<iostream>
using namespace std;


int ReadPoisitveNumbers(string Message);
void FibonacciSeriesUsingLoop(int Limit);

int main(){

    FibonacciSeriesUsingLoop(
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

void FibonacciSeriesUsingLoop(int Limit){
    int Prev2 = 1 , Prev1 = 0 , FibNumber;
    cout<<endl;
    for (int i = 1 ; i <= Limit ; i++){
        FibNumber = Prev2 + Prev1;
        cout<<FibNumber<<"  ";
        Prev2 = Prev1;
        Prev1 = FibNumber;
    }
    cout<<endl;
}