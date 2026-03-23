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
stDate IncreaseDateByXDays(stDate Date, short NumberOfDays);
stDate IncreaseDateByOneWeek(stDate Date);
stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeks);
stDate IncreaseDateByOneMonth(stDate Date);
stDate IncreaseDateByXMonths(stDate Date, short NumberOfMonths);
stDate IncreaseDateByOneYear(stDate Date);
stDate IncreaseDateByXYears(stDate Date, short NumberOfYears);
stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYears);
stDate IncreaseDateByOneDecade(stDate Date);
stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades);
stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades);
stDate IncreaseDateByOneCentury(stDate Date);
stDate IncreaseDateByOneMillennium(stDate Date);

int main()
{
    stDate Date = ReadFullDate();

    cout << "\nDate After: \n";

    Date = IncreaseDateByOneDay(Date);
    cout << "\n01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXDays(Date, 10);
    cout << "\n02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneWeek(Date);
    cout << "\n03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXWeeks(Date, 10);
    cout << "\n04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneMonth(Date);
    cout << "\n05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXMonths(Date, 5);
    cout << "\n06-Adding 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneYear(Date);
    cout << "\n07-Adding one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXYears(Date, 10);
    cout << "\n08-Adding 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Adding 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneDecade(Date);
    cout << "\n10-Adding one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXDecades(Date , 10);
    cout << "\n11-Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByXDecadesFaster(Date , 10);
    cout << "\n12-Adding 10 Decade (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneCentury(Date);
    cout << "\n13-Adding One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = IncreaseDateByOneMillennium(Date);
    cout << "\n14-Adding One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
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

stDate IncreaseDateByXDays(stDate Date, short NumberOfDays)
{
    for (int i = 1; i <= NumberOfDays; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, short NumberOfWeeks)
{
    for (int i = 1; i <= NumberOfWeeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (IsLastMonthInYear(Date))
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByXMonths(stDate Date, short NumberOfMonths)
{
    for (int i = 1; i <= NumberOfMonths; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByXYears(stDate Date, short NumberOfYears)
{
    for (int i = 1; i <= NumberOfYears; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short NumberOfYears)
{
    Date.Year += NumberOfYears;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short NumberOfDecades)
{
    for (short i = 1; i <= NumberOfDecades * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
{
    Date.Year += NumberOfDecades * 10;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
