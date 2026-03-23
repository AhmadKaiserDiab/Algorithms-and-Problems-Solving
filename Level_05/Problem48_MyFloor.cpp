#include <iostream>
#include <cmath>
using namespace std;

float ReadNumbers(string Message)
{
    float x;
    cout << Message << endl;
    cin >> x;
    return x;
}

int MyFloor(float Number){
    if(Number < 0 )
        Number = int(--Number);
    return Number;
}

int main() {
    float Number = ReadNumbers("Enter A Float Number: ");
    cout<<"My Floor: "<<MyFloor(Number);
    cout<<endl;
    cout<<"C++ Floor: "<<floor(Number);
    return 0;
}
