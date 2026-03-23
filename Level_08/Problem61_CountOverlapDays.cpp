#include <iostream>
using namespace std;

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

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
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualDate2(stDate Date1, stDate Date2);
bool IsDate1AfterDate2(stDate Date1, stDate Date2);
stDate IncreaseDateByOneDay(stDate Date);
enDateCompare CompareDates(stDate Date1, stDate Date2);
bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2);
short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay);
short CountOverlapDays(stPeriod Period1, stPeriod Period2);
bool IsLastMonthInYear(stDate Date);
bool IsLastDayInMonth(stDate Date);
short NumberOfDaysInAMonth(short Month, short Year);
bool IsLeapYear(short year);
void SwapPeriods(stPeriod & Period1, stPeriod & Period2);

int main()
{
    cout << "Enter Period 1" << endl;
    stPeriod Period1 = ReadFullPeriod();
    cout << "\n\nEnter Period 2" << endl;
    stPeriod Period2 = ReadFullPeriod();

    cout << "\n\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2) << endl;
}

int ReadPoisitveNumbers(string Message)
{
    int x;
    cout << Message;
    cin >> x;
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
    cout << "\nEnter Start Date: \n"
        << endl;
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date: \n"
        << endl;
    Period.EndDate = ReadFullDate();
    return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return Date1.Year == Date2.Year ? (
            Date1.Month == Date2.Month ? (
                Date1.Day == Date2.Day ? true : false)
                : false)
            : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
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

void SwapPeriods(stPeriod & Period1, stPeriod & Period2)
{
    stPeriod Temp = Period1;
    Period1 = Period2;
    Period2 = Temp;
}

short CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    if (!IsDate1BeforeDate2(Period1.StartDate, Period2.StartDate))
    {
        SwapPeriods(Period1, Period2);
    }

    short NumberOfDays = 0;

    while (IsDate1BeforeDate2(Period2.StartDate, Period1.EndDate) )
        {
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
            NumberOfDays++;
        }
        return NumberOfDays;
}
