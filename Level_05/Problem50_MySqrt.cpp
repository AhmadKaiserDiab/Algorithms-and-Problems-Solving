#include <iostream>
#include <cmath>
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

float MySqrt(int Number){
    return pow(Number,0.5);
}

int main() {
    int Number = ReadPoisitveNumbers("Enter A Positive Number: ");
    cout<<"My Sqrt: "<<MySqrt(Number);
    cout<<endl;
    cout<<"C++ Sqrt: "<<sqrt(Number);
    return 0;
}
