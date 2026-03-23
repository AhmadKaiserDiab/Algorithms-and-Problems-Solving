#include <iostream>
#include <ctime>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

int ReadPoisitveNumbers(string Message);
stDate ReadFullDate();
stPeriod ReadFullPeriod();
bool IsLeapYear(short year);
short NumberOfDaysInAMonth(short Month, short Year);
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(stDate Date);
stDate IncreaseDateByOneDay(stDate Date);
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay);
short GetPeriodLengthInDays(stPeriod Period, bool IncludeEndDate);

int main()
{
    stPeriod Period = ReadFullPeriod();

    cout << "\nPeriod Length is: "
        << GetPeriodLengthInDays(Period, false) << " Day(s).\n";

    cout << "\nPeriod Length (Including End Date) is: "
        << GetPeriodLengthInDays(Period, true) << " Day(s).\n";
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

stPeriod ReadFullPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date: \n"<<endl;
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date: \n"<<endl;
    Period.EndDate = ReadFullDate();
    return Period;
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
    return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(stDate Date)
{
    return Date.Month == 12;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

short GetPeriodLengthInDays(stPeriod Period, bool IncludeEndDate)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}
