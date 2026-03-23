#include <iostream>
using namespace std;

struct stDate{
    short Year;
    short Month;
    short Day;
};

int ReadPoisitveNumbers(string Message);
bool IsLeapYear(short year);
short NumberOfDaysInAMonth(short Month, short Year);
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year);
stDate DateFromDayOrder(short DayOrder , short Year);

int main()
{
    stDate Date;
    short Day = ReadPoisitveNumbers("Please Enter a Day: ");
    short Month = ReadPoisitveNumbers("Please Enter a Month: ");
    short Year = ReadPoisitveNumbers("Please Enter a Year: ");
    short TotalDays = NumberOfDaysFromTheBeginingOfTheYear(Day, Month, Year); 
    Date = DateFromDayOrder(TotalDays , Year);

    cout<<"Number of Days From The Beginning of The Year: "
        <<TotalDays<<endl;

    cout<<"\nDate For ["<<TotalDays<<"] is: "
        <<Date.Day<<"/"<<Date.Month<<"/"<<Date.Year<<endl;
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
    
    for ( short Counter = 1; Counter < Month ; Counter++)
    {
        TotalDays += NumberOfDaysInAMonth(Counter , Year);
    }
    return TotalDays + Day;
}

stDate DateFromDayOrder(short DayOrder , short Year)
{
    stDate Date;
    Date.Day = DayOrder;
    Date.Month = 1;
    Date.Year = Year;
    while (true)
    {
        short DaysInMonth = NumberOfDaysInAMonth(Date.Month,Year);
        if (DaysInMonth >= Date.Day)
        {
            break;
        }
        else
        {
            Date.Day-=DaysInMonth;
            Date.Month++;
        }
    }

    return Date;
}
