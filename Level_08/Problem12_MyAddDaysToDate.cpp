#include <iostream>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

int ReadPoisitveNumbers(string Message);
void ReadFullDate(stDate & Date);
bool IsLeapYear(short year);
short NumberOfDaysInYear(short Year);
short NumberOfDaysInAMonth(short Month, short Year);
void ModifyDate(stDate &Date, short AddDays);
void AddYears(stDate &Date, short &AddDays);
void AddMonths(stDate &Date, short &AddDays);
void CheckNumberOfMonths(stDate &Date);
void AddDays(stDate &Date, short &AddDays);
void CheckNumberOfDays(stDate &Date);

int main()
{
    stDate Date;
    ReadFullDate(Date);

    short DaystoAdd = ReadPoisitveNumbers("How Many Days To Add: ");
    ModifyDate(Date, DaystoAdd);

    cout << "\nDate After Adding [" << AddDays << "] Days is: "
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

void ReadFullDate(stDate & Date)
{
    Date.Day = ReadPoisitveNumbers("Please Enter a Day: ");
    Date.Month = ReadPoisitveNumbers("Please Enter a Month: ");
    Date.Year = ReadPoisitveNumbers("Please Enter a Year: ");
}

bool IsLeapYear(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short NumberOfDaysInYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365;
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

void ModifyDate(stDate &Date, short DaystoAdd)
{
    AddYears(Date, DaystoAdd);
    AddMonths(Date, DaystoAdd);
    AddDays(Date, DaystoAdd);
}

void AddYears(stDate &Date, short &DaystoAdd)
{
    while (true)
    {
        short NumOfDaysInYear = NumberOfDaysInYear(Date.Year);
        if (NumOfDaysInYear < DaystoAdd)
        {
            Date.Year++;
            DaystoAdd -= NumOfDaysInYear;
        }
        else
        {
            break;
        }
    }
}

void AddMonths(stDate &Date, short & DaystoAdd)
{
    while (true)
    {
        short NumOfDaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (NumOfDaysInMonth < DaystoAdd)
        {
            Date.Month++;
            DaystoAdd -= NumOfDaysInMonth;
            CheckNumberOfMonths(Date);
        }
        else
        {
            break;
        }
    }
}

void AddDays(stDate &Date, short &DaystoAdd)
{
    Date.Day += DaystoAdd;
    CheckNumberOfDays(Date);
}

void CheckNumberOfMonths(stDate &Date)
{
    if (Date.Month > 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
}

void CheckNumberOfDays(stDate &Date)
{
    short NumOfDaysInMonth = NumberOfDaysInAMonth(Date.Month , Date.Day);
    if (Date.Day > NumOfDaysInMonth )
    {
        Date.Day -= NumOfDaysInMonth;
        Date.Month++;
        CheckNumberOfMonths(Date);
    }
}
