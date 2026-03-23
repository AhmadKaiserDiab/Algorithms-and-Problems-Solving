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

int ReadPoisitveNumbers(string Message);
stDate ReadFullDate();
bool IsDate1BeforeDate2(stDate Date1, stDate Date2);
bool IsDate1EqualDate2(stDate Date1, stDate Date2);
bool IsDate1AfterDate2(stDate Date1, stDate Date2);
enDateCompare CompareDates(stDate Date1, stDate Date2);

int main()
{
    cout << "\nEnter Date1\n"<< endl;
    stDate Date1 = ReadFullDate();
    cout << "\nEnter Date2\n"<< endl;
    stDate Date2 = ReadFullDate();

    printf("\nCompare Result = %d\n", CompareDates(Date1, Date2));
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return Date1.Year == Date2.Year ? (
                Date1.Month == Date2.Month ? (
                    Date1.Day == Date2.Day ? true : false) : false)
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
