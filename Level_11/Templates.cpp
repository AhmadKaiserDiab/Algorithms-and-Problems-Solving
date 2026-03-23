#include <iostream>
using namespace std;
//! Example about using "template" functions and classes

// ? Template Function
template <typename X > X MyMax(X Number1, X Number2)
{
    return Number1 >= Number2 ? Number1 : Number2 ; 
}

// ? Template Class
template <class T> class Calculator
{
    private:
        T _Number1 , _Number2;

    public:
        Calculator(T Number1 , T Number2)
        {
            _Number1 = Number1;
            _Number2 = Number2;
        };

        T Add()
        {
            return _Number1 + _Number2;
        }

        T Subtract()
        {
            return _Number1 - _Number2;
        }

        T Multiply()
        {
            return _Number1 * _Number2;
        }

        T Divide()
        {
            _Number2 = _Number2 == 0 ? 1 : _Number1;
            return _Number1 / _Number2;
        }

        void PrintResults()
        {
            cout<<endl;
            cout<< "Numbers: " << _Number1 << " and " << _Number2 << "." <<endl;
            cout<< _Number1 << " + " << _Number2 << " = " << Add() <<endl;
            cout<< _Number1 << " - " << _Number2 << " = " << Subtract() <<endl;
            cout<< _Number1 << " * " << _Number2 << " = " << Multiply() <<endl;
            cout<< _Number1 << " / " << _Number2 << " = " << Divide() <<endl;
        }

};

int main()
{
    cout<<"\n"<<MyMax<int>(1,3);
    cout<<"\n"<<MyMax<float>(11.6,3.1);
    cout<<"\n"<<MyMax<char>('A','z');
    
    cout<<"\n___________________________\n";
    Calculator<int> C1(1,6);
    C1.PrintResults();
    cout<<"\n___________________________\n";
    Calculator<double> C2(3.7,5.1);
    C2.PrintResults();
    cout<<"\n___________________________\n";
    Calculator<char> C3('A','a');
    C3.PrintResults();
}