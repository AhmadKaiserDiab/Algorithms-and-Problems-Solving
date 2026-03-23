#include<iostream>
using namespace std;

char ReadChar(string Message);
bool CheckLetterIsVowel(char Character);

int main()
{

    char Letter = ReadChar("Please Enter a Character: ");

    if(CheckLetterIsVowel(Letter))
        cout<<"\nYes, Letter \'"<<Letter
            <<"\' Is Vowel"<<endl;
    else
        cout<<"\nNo, Letter \'"<<Letter
            <<"\' Is Not Vowel"<<endl;
}

char ReadChar(string Message)
{
    char ch;
    cout<<Message<<endl;
    cin>>ch;
    cout<<endl;
    return ch;
}

bool CheckLetterIsVowel(char ch)
{
    ch = tolower(ch);
    return (ch== 'a') || (ch== 'e') || (ch== 'i') || (ch== 'o') || (ch== 'u');
}