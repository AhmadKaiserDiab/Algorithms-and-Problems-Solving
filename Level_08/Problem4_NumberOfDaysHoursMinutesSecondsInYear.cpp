#include <iostream>
using namespace std;

struct stYear
{
    short numberOfDaysInYear;
    short numberOfHoursInYear;
    int numberOfMinutesInYear;
    int numberOfSecondsInYear;
};

bool IsLeapYear(short year);
stYear GetYearDetails(short Year);
void PrintYearDetails(short year);

int main()
{
    short year;
    cout << "\nPlese Enter a Year to Check: ";
    cin >> year;
    PrintYearDetails(year);
}

bool IsLeapYear(short year)
{
    return ( year % 400 == 0 ) || ( year % 4 == 0 && year % 100 != 0 );
}

stYear GetYearDetails(short Year)
{
    stYear TempYear;

    TempYear.numberOfDaysInYear = IsLeapYear(Year) ? 366 : 365;
    TempYear.numberOfHoursInYear = TempYear.numberOfDaysInYear * 24;
    TempYear.numberOfMinutesInYear = TempYear.numberOfHoursInYear * 60;
    TempYear.numberOfSecondsInYear = TempYear.numberOfMinutesInYear * 60;

    return TempYear;
}

void PrintYearDetails(short Year)
{
    stYear stYearDetails = GetYearDetails(Year);

    cout << "\nNumber Of Days    In Year [" << Year << "] is: " 
        << stYearDetails.numberOfDaysInYear << endl;
    cout << "Number Of Hours   In Year [" << Year << "] is: " 
        << stYearDetails.numberOfHoursInYear << endl;
    cout << "Number Of Minutes In Year [" << Year << "] is: " 
        << stYearDetails.numberOfMinutesInYear << endl;
    cout << "Number Of Seconds In Year [" << Year << "] is: " 
        << stYearDetails.numberOfSecondsInYear << endl;
}
