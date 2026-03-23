#include<iostream>
using namespace std;

string ReadString(string Message);
void PrintCharactersCountInString(string Line);
short CountSmallLetters(string Line);
short CountCapitalLetters(string Line);
short CountSpecialLetters(string Line);
short CountEmptyCharacters(string Line);
short CountNumbers(string Line);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    PrintCharactersCountInString(Line);
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

void PrintCharactersCountInString(string Line)
{
    cout<<"\nString Length =            "<<Line.length()<<endl;

    cout<<"Capital Letters Count =    "<<
            CountCapitalLetters(Line)
            <<endl;

    cout<<"Small Letters Count =      "<<
            CountSmallLetters(Line)
            <<endl;

    cout<<"Special Characters Count = "<<
            CountSpecialLetters(Line)
            <<endl;

    cout<<"Numbers Count =            "<<
            CountNumbers(Line)
            <<endl;

    cout<<"Empty Charactes Count =    "<<
            CountEmptyCharacters(Line)
            <<endl;
}

short CountSmallLetters(string Line)
{
    short SmallLettersCount = 0;
    for (int i = 0; i < Line.length(); i++)
        if(islower(Line[i]))
            SmallLettersCount++;
    return SmallLettersCount;
}

short CountCapitalLetters(string Line)
{
    short CapitalLettersCount = 0;
    for (int i = 0; i < Line.length(); i++)
        if(isupper(Line[i]))
            CapitalLettersCount++;
    return CapitalLettersCount;
}

short CountSpecialLetters(string Line)
{
    short SpecialLettersCount = 0;
    for (int i = 0; i < Line.length(); i++)
        if(ispunct(Line[i]))
            SpecialLettersCount++;
        return SpecialLettersCount;
}

short CountNumbers(string Line)
{
    short NumbersCount = 0;
    for (int i = 0; i < Line.length(); i++)
        if(isdigit(Line[i]))
            NumbersCount++;
        return NumbersCount;
}

short CountEmptyCharacters(string Line)
{
    short EmptyCharactersCount = 0;
    for (int i = 0; i < Line.length(); i++)
        if(isspace(Line[i]))
            EmptyCharactersCount++;
        return EmptyCharactersCount;
}


//! ANOTHER SOlUTION
/*
#include <string>
#include <iostream>
using namespace std;
string ReadString() {
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
enum enWhatToCount { SmallLetters=0 , CapitalLetters=1 , All=3 };
short CountLetters(string S1, enWhatToCount WhatToCount=enWhatToCount::All ) {
    if (WhatToCount == enWhatToCount::All) {
        return S1.length();
    }
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++) {
        if (WhatToCount==enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
            Counter++;
    }
    return Counter;
}

short CountCapitalLetters(string S1) {
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++) {
        if (isupper(S1[i]))
        Counter++;
    }
    return Counter;
}

short CountSmallLetters(string S1) {
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++) {
        if (islower(S1[i]))
            Counter++;
    }
    return Counter;
}

int main() {
    string S1 = ReadString();
    cout<< "\nString Length = " << S1.length();
    cout<< "\nCapital Letters Count= " 
        <<CountCapitalLetters(S1);

    cout<< "\nSmall Letters Count= " << CountSmallLetters(S1);

    cout<< "\n\nMethod 2\n";
    cout<< "\nString Length = " << CountLetters(S1);

    cout<< "\nCapital Letters Count= " 
        << CountLetters(S1,enWhatToCount::CapitalLetters);

    cout<< "\nSmall Letters Count= " 
        <<CountLetters(S1,enWhatToCount::SmallLetters );

    system("pause>0");
}

*/ 