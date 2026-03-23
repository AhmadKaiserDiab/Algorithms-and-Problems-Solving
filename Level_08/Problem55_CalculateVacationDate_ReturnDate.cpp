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
void PrintFullDate(stDate Date);
short DayOfWeekOrder(short Day, short Month, short Year);
string DayShortName(short DayOfWeekOrder);
bool IsLeapYear(short year);
bool IsWeekEnd(stDate Date);
bool IsBusinessDay(stDate Date);
bool IsLastDayInMonth(stDate Date);
bool IsLastMonthInYear(stDate Date);
stDate IncreaseDateByOneDay(stDate Date);
stDate CalculateVacationEndDate(stDate StartDate, short NumberOfDays);

int main()
{
    stDate StartDate , EndDate;
    cout << "\nVacation Starts: \n\n";
    StartDate = ReadFullDate();

    short VacationDays = ReadPoisitveNumbers("Pleae Enter Vacation Days: ");
    EndDate = CalculateVacationEndDate(StartDate, VacationDays);

    cout << "\n\nReturn Date: ";
    PrintFullDate(EndDate);

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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((m * 31) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

void PrintFullDate(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    printf(" %s , %d/%d/%d \n",
        DayShortName(DayOrder).c_str(), Date.Day, Date.Month, Date.Year);
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

bool IsWeekEnd(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekEnd(Date));
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

stDate CalculateVacationEndDate(stDate StartDate, short NumberOfDays)
{
    while (NumberOfDays != 0)
    {
        if (IsBusinessDay(StartDate))
        {
            NumberOfDays--;
        }
        StartDate = IncreaseDateByOneDay(StartDate);
    }
    return StartDate;
}
