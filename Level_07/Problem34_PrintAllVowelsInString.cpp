#include<iostream>
using namespace std;

string ReadString(string Message);
bool CheckLetterIsVowel(char Ch);
void PrintEachVowelInString(string Line);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    PrintEachVowelInString(Line);
}

string ReadString(string Message)
{
    string s;
    cout<<Message<<endl;
    getline(cin,s);
    cout<<endl;
    return s;
}

bool CheckLetterIsVowel(char ch)
{
    ch = tolower(ch);
    return (ch== 'a') || (ch== 'e') || (ch== 'i') || (ch== 'o') || (ch== 'u');
}

void PrintEachVowelInString(string S)
{
    cout<<"All Vowels In String is: ";
    for (int i = 0; i < S.length(); i++)
        if(CheckLetterIsVowel(S[i]))
            cout<<S[i]<<"   ";
    cout<<endl;
}