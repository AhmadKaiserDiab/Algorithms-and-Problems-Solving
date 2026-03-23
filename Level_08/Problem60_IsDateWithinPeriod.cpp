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
enDateCompare CompareDates(stDate Date1, stDate Date2);
bool IsDateWithinPeriod(stPeriod Period, stDate Date);

int main()
{
    cout << "Enter Period " << endl;
    stPeriod Period = ReadFullPeriod();
    cout << "\n\nEnter a Date To Check\n" << endl;
    stDate Date = ReadFullDate();

    if (IsDateWithinPeriod(Period, Date))
        cout << "Yes, Date is Within Period" << endl;
    else
        cout << "No, Date is NOT Within Period" << endl;
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return Date1.Year == Date2.Year ? (
        Date1.Month == Date2.Month ? (
            Date1.Day == Date2.Day ? true : false) : false
        ) : false;
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

bool IsDateWithinPeriod(stPeriod Period, stDate Date)
{
    return (CompareDates(Period.StartDate, Date) == enDateCompare::Before &&
            CompareDates(Period.EndDate,Date) == enDateCompare::After);
}
