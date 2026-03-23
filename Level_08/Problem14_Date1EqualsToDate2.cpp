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
bool IsDate1EqualDate2(stDate Date1, stDate Date2);

int main()
{
    stDate Date1 = ReadFullDate();
    stDate Date2 = ReadFullDate();

    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 Is Equal To Date2\n";
    else
        cout << "\n No, Date1 Is NOT Equal To Date2\n";
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return  Date1.Year == Date2.Year ? ( 
                Date1.Month == Date2.Month ? (
                    Date1.Day == Date2.Day  ? true : false ) : false ) : false ;
}