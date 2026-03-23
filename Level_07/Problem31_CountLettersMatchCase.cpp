#include<iostream>
using namespace std;

string ReadString(string Message);
char InvertLetterCase(char character);
void PrintCharactersCountInString(string Line);
short GetCharacterCountInString(string Line , char Character);
short CountAllMatchingCharacter(string Line , char Character);

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
    char Character;
    cout<<"\nplease Enter A Character: ";
    cin>>Character;

    cout<<"\nLetter \'"<<Character<<"\' Count = "
        << GetCharacterCountInString(Line, Character);

    cout<<"\nLetter \'"<<Character<<"\' Or \'"
        <<InvertLetterCase(Character) <<"\' Count = "
        << CountAllMatchingCharacter(Line, Character);
}

char InvertLetterCase(char character)
{
    return isupper(character) ? tolower(character) : toupper(character) ;
}

short GetCharacterCountInString(string Line , char Character)
{
    short CharacterCount = 0;
    for (int i = 0 ; i < Line.length();i++)
        if(Line[i] == Character)
            CharacterCount++;
    return CharacterCount;
}

short CountAllMatchingCharacter(string Line , char Character)
{
    short CharacterCount = 0;
    for (int i = 0 ; i < Line.length();i++)
        if(Line[i] == toupper(Character) || Line[i] == tolower(Character) )
            CharacterCount++;
    return CharacterCount;
}