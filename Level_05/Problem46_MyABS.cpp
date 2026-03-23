#include <iostream>
using namespace std;

float ReadNumbers(string Message)
{
    float x;
    cout << Message << endl;
    cin >> x;
    return x;
}

float MyABS(float Number){
    if(Number < 0)
        Number*=-1;
    return Number;
}

int main()
{
    float Number = ReadNumbers("Enter A Number: ");
    cout<<"My ABS: "<< MyABS(Number);
    cout<<endl;
    cout<<"C++ ABS: "<<abs(Number);
    return 0;
}
