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

stDate DecreaseDateByOneDay(stDate Date);
stDate DecreaseDateByXDays(stDate Date, short NumberOfDays);
stDate DecreaseDateByOneWeek(stDate Date);
stDate DecreaseDateByXWeeks(stDate Date, short NumberOfWeeks);
stDate DecreaseDateByOneMonth(stDate Date);
stDate DecreaseDateByXMonths(stDate Date, short NumberOfMonths);
stDate DecreaseDateByOneYear(stDate Date);
stDate DecreaseDateByXYears(stDate Date, short NumberOfYears);
stDate DecreaseDateByXYearsFaster(stDate Date, short NumberOfYears);
stDate DecreaseDateByOneDecade(stDate Date);
stDate DecreaseDateByXDecades(stDate Date, short NumberOfDecades);
stDate DecreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades);
stDate DecreaseDateByOneCentury(stDate Date);
stDate DecreaseDateByOneMillennium(stDate Date);

int main()
{
    stDate Date = ReadFullDate();

    cout << "\nDate After: \n";

    Date = DecreaseDateByOneDay(Date);
    cout << "\n01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXDays(Date, 10);
    cout << "\n02-Subtracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByOneWeek(Date);
    cout << "\n03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXWeeks(Date, 10);
    cout << "\n04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByOneMonth(Date);
    cout << "\n05-Subtracting one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXMonths(Date, 5);
    cout << "\n06-Subtracting 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByOneYear(Date);
    cout << "\n07-Subtracting one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXYears(Date, 10);
    cout << "\n08-Subtracting 10 Years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXYearsFaster(Date, 10);
    cout << "\n09-Subtracting 10 Years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByOneDecade(Date);
    cout << "\n10-Subtracting one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXDecades(Date , 10);
    cout << "\n11-Subtracting 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByXDecadesFaster(Date , 10);
    cout << "\n12-Subtracting 10 Decade (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByOneCentury(Date);
    cout << "\n13-Subtracting One Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
    
    Date = DecreaseDateByOneMillennium(Date);
    cout << "\n14-Subtracting One Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;
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

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInAMonth(Date.Month , Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate DecreaseDateByXDays(stDate Date, short NumberOfDays)
{
    for (int i = 1; i <= NumberOfDays; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeeks(stDate Date, short NumberOfWeeks)
{
    for (int i = 1; i <= NumberOfWeeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short NumberOfMonths)
{
    for (int i = 1; i <= NumberOfMonths; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXYears(stDate Date, short NumberOfYears)
{
    for (int i = 1; i <= NumberOfYears; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short NumberOfYears)
{
    Date.Year -= NumberOfYears;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByXDecades(stDate Date, short NumberOfDecades)
{
    for (short i = 1; i <= NumberOfDecades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short NumberOfDecades)
{
    Date.Year -= NumberOfDecades * 10;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
