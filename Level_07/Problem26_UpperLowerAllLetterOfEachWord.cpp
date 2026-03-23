#include<iostream>
using namespace std;

string ReadString(string Message);
string UpperAllLettersInString(string Line) ;
string LowerAllLettersInString(string Line) ;

int main()
{
    string Line = ReadString("Please Enter Your String: ");

    cout<<"\nYour String After Upper All Letters:\n "
        <<UpperAllLettersInString(Line)<<"\n\n";
    
    cout<<"Your String After Lower All Letters:\n "
        <<LowerAllLettersInString(Line)<<"\n";
}

string ReadString(string Message) 
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

string UpperAllLettersInString(string line)
{
    for (int i = 0; i < line.size(); i++)
        line[i] = toupper(line[i]);
    return line;
}

string LowerAllLettersInString(string line)
{
    for (int i = 0; i < line.size(); i++)
        line[i] = tolower(line[i]);
    return line;
}