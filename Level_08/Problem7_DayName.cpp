#include <iostream>
using namespace std;

int ReadPoisitveNumbers(string Message);
void PrintDayDetails(short Day, short Month, short Year);
short DayOfWeekOrder(short Day, short Month, short Year);
string DayShortName(short DayOfWeekOrder) ;

int main()
{
    short Year = ReadPoisitveNumbers("Please Enter a Year: ");
    short Month = ReadPoisitveNumbers("Please Enter a Month: ");
    short Day = ReadPoisitveNumbers("Please Enter a Day: ");
    PrintDayDetails(Day, Month, Year);
}

void PrintDayDetails(short Day, short Month, short Year)
{
    short DayOrder = DayOfWeekOrder(Day, Month, Year);

    string arrDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                        "Thursday", "Friday", "Saturday"};

    printf("Date      : %0.2d/%0.2d/%d\n", Day, Month, Year);
    printf("Day Order : %d\n", DayOrder);
    cout << "Day Name  : " << DayShortName(DayOrder) << endl;
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
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" }; 
    return arrDayNames[DayOfWeekOrder];
}
