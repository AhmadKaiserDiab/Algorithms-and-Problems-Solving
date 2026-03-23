#include<iostream>
using namespace std;

string ReadString(string Message);
string LowerFirstLetterOfEachWord(string &word) ;

int main()
{

    string Line = ReadString("Please Enter Your String: ");

    LowerFirstLetterOfEachWord(Line);
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

string LowerFirstLetterOfEachWord(string & Line)
{
    bool isFirstLetter = true;
    for (int i = 0; i < Line.size(); i++) {
        if(Line[i] !=  ' ' && isFirstLetter)
            Line[i] = tolower(Line[i]);
        isFirstLetter = Line[i] ==  ' ' ? true : false ;
    }
    return Line;
}