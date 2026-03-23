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

float MyABS(float Number){
    if(Number < 0)
        Number*=-1;
    return Number;
}

float CalcFractionPart(float Number){
    return MyABS(Number - (int)Number);
}

int MyRound(float Number){

    int Fraction = CalcFractionPart(Number) * 10;
    int TruePart = int(Number);
    if(Fraction>=5)
        if(TruePart >= 0 )
            TruePart++;
        else
            TruePart--;
    return TruePart;
}

int main() {
    float Number = ReadNumbers("Enter A Float Number: ");
    cout<<"My Round: "<<MyRound(Number);
    cout<<endl;
    cout<<"C++ Round: "<<round(Number);
    return 0;
}
