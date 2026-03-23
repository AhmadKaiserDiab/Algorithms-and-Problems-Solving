#include <iostream>
#include <iomanip>
using namespace std;

int ReadPoisitveNumbers(string Message);
bool IsLeapYear(short year);
short NumberOfDaysInAMonth(short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);
void PrintMonthCalender(short Month, short Year);
string MonthShortName(short MonthNumber);
void PrintMonthDays(short FirstDayInMonth, short NumberOfDays);
void PrintYearCalender(short Year);

int main()
{
    short Year = ReadPoisitveNumbers("Please Enter a Year: ");
    PrintYearCalender(Year);
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

string MonthShortName(short MonthNumber)
{
    string Months[12] =
        {
            "Jan", "Feb", "Mar",
            "Apr", "May", "Jun",
            "Jul", "Aug", "Sep",
            "Oct", "Nov", "Dec"};
    return (Months[MonthNumber - 1]);
}

void PrintMonthCalender(short Month, short Year)
{
    short FirstDayInMonth = DayOfWeekOrder(1, Month, Year);
    short NumberOfDays = NumberOfDaysInAMonth(Month, Year);

    printf("________________%s________________\n\n",
           MonthShortName(Month).c_str());

    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"
         << endl;

    PrintMonthDays(FirstDayInMonth, NumberOfDays);
    cout << "\n___________________________________" << endl;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((m * 31) / 12)) % 7;
}

void PrintMonthDays(short FirstDayInMonth, short NumberOfDays)
{
    int i;
    for (i = 0; i < FirstDayInMonth; i++)
        printf("     ");
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);
        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
}

void PrintYearCalender(short Year)
{
    printf("\n _________________________________\n\n");
    printf("      Calendar - %d\n", Year);
    printf(" _________________________________\n\n");

    for (int Month = 1; Month <= 12; Month++)
    {
        PrintMonthCalender(Month, Year);
        cout << "\n"<< endl;
    }
}

/*
void PrintMonthDays(short FirstDayInMonth, short NumberOfDays)
{
    for (short DayIndex = 0, Day = 0; Day <= NumberOfDays;DayIndex++)
    {
        if (DayIndex == 7)
        {
            cout << endl;
            DayIndex = 0;
        }
        if (DayIndex < FirstDayInMonth - 1 && Day == 0)
        {
            cout << setw(5) << Day;
        }
        else
        {
            cout << setw(5) << Day++;
        }
    }
}
 */