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
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year);
stDate DateAddDays(short Days, stDate Date);

int main()
{
    stDate Date = ReadFullDate();
    short DaystoAdd = ReadPoisitveNumbers("How Many Days To Add: ");
    Date = DateAddDays(DaystoAdd, Date);

    cout << "\nDate After Adding [" << DaystoAdd << "] Days is: "
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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short Counter = 1; Counter < Month; Counter++)
    {
        TotalDays += NumberOfDaysInAMonth(Counter, Year);
    }
    return TotalDays + Day;
}

stDate DateAddDays(short Days, stDate Date)
{
    short RemainingDays = Days +
            NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while (true)
    {
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}
