#include<iostream>
using namespace std;

char ReadChar(string Message);
char InvertLetterCase(char Character);

int main()
{

    char character = ReadChar("Please Enter a Character: ");

    cout<<"\n Character After Inverting Case:\n "
        <<InvertLetterCase(character)<<"\n\n";
}

char ReadChar(string Message)
{
    char C;
    cout<<Message<<endl;
    cin>>C;
    cout<<endl;
    return C;
}

char InvertLetterCase(char character)
{
    return isupper(character) ? tolower(character) : toupper(character) ;
}