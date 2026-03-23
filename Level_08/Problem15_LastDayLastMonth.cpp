#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

int ReadPoisitveNumbers(string Message);
stDate ReadFullDate();
bool IsLeapYear(short year);
short NumberOfDaysInAMonth(short Month, short Year);
bool IsLastDayInMonth(stDate Date); 
bool IsLastMonthInYear(stDate Date);

int main()
{
    stDate Date1 = ReadFullDate();

    if (IsLastDayInMonth(Date1))
        cout << "\nYes, Day Is Last In Month\n";
    else
        cout << "\n No, Day Is NOT Last In Month\n";
    
    if (IsLastMonthInYear(Date1))
        cout << "\nYes, Month Is Last In Year\n";
    else
        cout << "\n No, Month Is NOT Last In Year\n";
}

int ReadPoisitveNumbers(string Message)
{
    int x;
    do
    {
        cout << Message;
        cin >> x;
    } while (x < 0);
    cout << endl;
    return x;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadPoisitveNumbers("Please Enter a Day: ");
    Date.Month = ReadPoisitveNumbers("Please Enter a Month: ");
    Date.Year = ReadPoisitveNumbers("Please Enter a Year: ");
    return Date;
}

bool IsLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    else
    {
        short numberOfdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2 && IsLeapYear(Year)) ? 29 : numberOfdays[Month - 1];
    }
}

bool IsLastDayInMonth(stDate Date)
{
    return  Date.Day == NumberOfDaysInAMonth(Date.Month , Date.Year)  ;
}

bool IsLastMonthInYear(stDate Date)
{
    return  Date.Month == 12  ;
}