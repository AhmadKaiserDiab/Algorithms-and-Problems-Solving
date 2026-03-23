#include <iostream>
using namespace std;

struct stMonth
{
    short numberOfDaysInMonth;
    short numberOfHoursInMonth;
    int numberOfMinutesInMonth;
    int numberOfSecondsInMonth;
};

bool IsLeapYear(short year);
stMonth GetMonthDetails(short Month , short Year);
void PrintMonthDetails(short year);

//! Using Short Logic
int main()
{
    short year;
    cout << "\nPlese Enter a Year to Check: ";
    cin >> year;
    PrintMonthDetails(year);
}

bool IsLeapYear(short year)
{
    return ( year % 400 == 0 ) || ( year % 4 == 0 && year % 100 != 0 );
}

stMonth GetMonthDetails(short Month , short Year)
{
    stMonth TempMonth;

        if (Month < 1 || Month > 12 )
    {
        TempMonth.numberOfDaysInMonth = 0;
    }
    else
    {
        short numberOfdays [12]  =  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        TempMonth.numberOfDaysInMonth = (Month == 2 && IsLeapYear(Year)) ? 
                                        29 : numberOfdays[ Month-1] ;
    }

    TempMonth.numberOfHoursInMonth = TempMonth.numberOfDaysInMonth * 24;
    TempMonth.numberOfMinutesInMonth = TempMonth.numberOfHoursInMonth * 60;
    TempMonth.numberOfSecondsInMonth = TempMonth.numberOfMinutesInMonth * 60;

    return TempMonth;
}

void PrintMonthDetails(short Year)
{
    short Month;
    cout << "\nPlese Enter a Month to Check: ";
    cin>>Month;

    stMonth stMonthDetails = GetMonthDetails(Month , Year);

    cout << "\nNumber Of Days    In Month [" << Month << "] is: " 
        << stMonthDetails.numberOfDaysInMonth << endl;
    cout << "Number Of Hours   In Month [" << Month << "] is: " 
        << stMonthDetails.numberOfHoursInMonth << endl;
    cout << "Number Of Minutes In Month [" << Month << "] is: " 
        << stMonthDetails.numberOfMinutesInMonth << endl;
    cout << "Number Of Seconds In Month [" << Month << "] is: " 
        << stMonthDetails.numberOfSecondsInMonth << endl;
}


// stMonth GetMonthDetails(short Year , short Month){
//     stMonth TempMonth;

//     if (Month < 1 || Month > 12 )
//     {
//         TempMonth.numberOfDaysInMonth = 0;
//     }

//     else if (Month == 4 || Month == 6 ||Month == 9 ||Month == 11 )
//     {
//         TempMonth.numberOfDaysInMonth = 30;
//     }
    
//     else if (Month == 2)
//     {
//         TempMonth.numberOfDaysInMonth = IsLeapYear(Year) ? 29 : 28;
//     }
//     else
//     {
//         TempMonth.numberOfDaysInMonth = 31;
//     }

//     TempMonth.numberOfHoursInMonth = TempMonth.numberOfDaysInMonth * 24;
//     TempMonth.numberOfMinutesInMonth = TempMonth.numberOfHoursInMonth * 60;
//     TempMonth.numberOfSecondsInMonth = TempMonth.numberOfMinutesInMonth * 60;

//     return TempMonth;
// }