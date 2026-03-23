#include<iostream>
using namespace std;

string ReadString(string Message);
bool CheckLetterIsVowel(char c1);
short GetAllVowelLettersCountInString(string Line);

int main()
{

    string Line = ReadString("Please Enter Your String: ");

    cout<<"Number Of Vowels is: "
        <<GetAllVowelLettersCountInString(Line)
        <<endl;
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

short GetAllVowelLettersCountInString(string S)
{
    short VowelsCount = 0;
    for (int i = 0; i < S.length(); i++)
        if(CheckLetterIsVowel(S[i]))
            VowelsCount++;
    return VowelsCount;
}