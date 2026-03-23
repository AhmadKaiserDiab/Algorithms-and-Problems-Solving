#include<iostream>
using namespace std;

string ReadString(string Message);
string UpperFirstLetterOfEachWord(string &word) ;

int main()
{

    string Line = ReadString("Please Enter Your String: ");

    UpperFirstLetterOfEachWord(Line);
    cout<<"Your string after Conversion:\n "
        <<Line
        <<endl;
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

string UpperFirstLetterOfEachWord(string & Line)
{
    bool isFirstLetter = true;
    for (int i = 0; i < Line.size(); i++) {
        if(Line[i] !=  ' ' && isFirstLetter)
            Line[i] = toupper(Line[i]);
        isFirstLetter = Line[i] ==  ' ' ? true : false ;
    }
    return Line;
}