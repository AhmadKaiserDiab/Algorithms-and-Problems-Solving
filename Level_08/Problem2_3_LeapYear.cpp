#include <iostream>
using namespace std;

bool IsLeapYear(short year);

//! Using Short Logic
int main()
{
    short year;
    cout << "Enter Year: ";
    cin >> year;

    if (IsLeapYear(year))

        cout << year << " is a LEAP Year." << endl;

    else
        cout << year << " is not a LEAP Year." << endl;
}

bool IsLeapYear(short year)
{
    return ( year % 400 == 0 ) || ( year % 4 == 0 && year % 100 != 0 );
}