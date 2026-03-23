#include <iostream>
#include <vector>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadStringDate();
vector<string> SplitString(string S1, string Seperator);
string DateToString(stDate Date);
stDate StringToDate(string Date);
string ReplaceWord(string S1, string StringToReplace, string sRepalceTo);
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy");

int main()
{
    string s1 = ReadStringDate();
    stDate Date = StringToDate(s1);

    cout<< "\n" <<endl;
    cout<< "\n" << FormateDate(Date) << "\n"; 
    cout<< "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n"; 
    cout<< "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n"; 
    cout<< "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n"; 
    cout<< "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n"; 
    cout<< "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
}

string ReadStringDate()
{
    string Date;
    cout << "Please Enter Date dd/mm/yyyy: ";
    getline(cin >> ws, Date);
    return Date;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

stDate StringToDate(string DateString)
{
    stDate Date;
    vector<string> vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);
    return Date;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWord(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace); // find next
    }
    return S1;
}

string FormateDate(stDate Date, string DateFormat )
{
    string FormattedDateString = "";

    FormattedDateString = ReplaceWord(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWord(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWord(FormattedDateString, "yyyy", to_string(Date.Year));
    return FormattedDateString;
}
