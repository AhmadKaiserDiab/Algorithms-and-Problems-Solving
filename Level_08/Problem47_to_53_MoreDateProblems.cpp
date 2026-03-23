#include <iostream>
#include <ctime>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

stDate GetSystemDate();
short DayOfWeekOrder(short Day, short Month, short Year);
short DayOfWeekOrder(stDate Date);
string DayShortName(short DayOfWeekOrder);
void PrintFullDate(stDate Date);
bool IsLeapYear(short year);
short NumberOfDaysInAMonth(short Month, short Year);
short DaysUntilEndOfTheMonth(stDate Date);
bool IsEndOfWeek(stDate Date);
bool IsWeekEnd(stDate Date);
bool IsBusinessDay(stDate Date);
short DaysUntilEndOfTheWeek(stDate Date);
short NumberOfDaysInAYear(short Year);
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year);
short DaysUntilEndOfTheYear(stDate Date);

int main()
{
    stDate Date = GetSystemDate();
    PrintFullDate(Date);

    cout<<"\n\nIs It The End Of The Week?\n";
    if(IsEndOfWeek(Date))
        cout<<"Yes, It is The End Of The Week\n";
    else    
        cout<<"No,Is It Not The End Of The Week.\n";

    cout<<"\n\nIs It a Week End Day?\n";
    if(IsWeekEnd(Date))
        cout<<"Yes, It is a Week End Day.\n";
    else    
        cout<<"No,Is It Not a Week End Day.\n";

    cout<<"\n\nIs It A Business Day?\n";
    if(IsBusinessDay(Date))
        cout<<"Yes, It is A Business Day.\n\n";
    else    
        cout<<"No,Is It Not A Business Day.\n\n";

    cout<<"Days Until The End Of The Week: "
        <<DaysUntilEndOfTheWeek(Date)<<" Days. \n";

    cout<<"Days Until The End Of The Month: "
        <<DaysUntilEndOfTheMonth(Date)<<" Days. \n";

    cout<<"Days Until The End Of The Year: "
        <<DaysUntilEndOfTheYear(Date)<<" Days. \n";
}

stDate GetSystemDate()
{
    stDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
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

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder) 
{
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
    return arrDayNames[DayOfWeekOrder];
}

void PrintFullDate(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date.Day,Date.Month ,Date.Year);
    printf("Today Is %s , %d/%d/%d \n" , 
    DayShortName(DayOrder).c_str(), Date.Day, Date.Month, Date.Year);
}

bool IsEndOfWeek(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date);
    return (DayOrder == 6);
}

bool IsWeekEnd(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date);
    return (DayOrder == 5 || DayOrder == 6 );
}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekEnd(Date));
}

short DaysUntilEndOfTheWeek(stDate Date)
{
    short DayOrder = DayOfWeekOrder(Date);
    return 6 - DayOrder ;
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

short DaysUntilEndOfTheMonth(stDate Date)
{
    short RemainingDays = NumberOfDaysInAMonth(Date.Month , Date.Year) - Date.Day;
    return RemainingDays;
}

short NumberOfDaysInAYear(short Year)
{
    return IsLeapYear(Year) ? 366 : 365 ;
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

short DaysUntilEndOfTheYear(stDate Date)
{
    short RemainingDays = NumberOfDaysInAYear(Date.Year) - 
        NumberOfDaysFromTheBeginingOfTheYear(Date.Day , Date.Month , Date.Year);
    return RemainingDays;
}
