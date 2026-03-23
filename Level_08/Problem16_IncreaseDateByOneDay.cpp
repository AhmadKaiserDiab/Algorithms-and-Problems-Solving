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
stDate IncreaseDateByOneDay(stDate Date);

int main()
{
    stDate Date = ReadFullDate();
    Date = IncreaseDateByOneDay(Date);

    cout << "\nDate After Adding One Days is: "
        << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
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

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}
