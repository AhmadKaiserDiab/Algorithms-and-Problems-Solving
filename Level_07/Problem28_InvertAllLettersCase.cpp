#include<iostream>
using namespace std;

string ReadString(string Message);
char InvertLetterCase(char character);
string InvertAllLettersCase(string Line);

int main()
{

    string Line = ReadString("Please Enter Your String: ");

    cout<<"\nYour String After Inverting All Letters Case:\n "
        <<InvertAllLettersCase(Line)<<"\n\n";

}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

char InvertLetterCase(char character)
{
    return isupper(character) ? tolower(character) : toupper(character) ;
}

string InvertAllLettersCase(string line)
{
    for (int i = 0; i < line.size(); i++)
        line[i] = InvertLetterCase(line[i]);
    return line;
}
