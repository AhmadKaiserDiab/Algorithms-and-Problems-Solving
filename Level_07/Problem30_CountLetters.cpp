#include<iostream>
using namespace std;

char ReadChar(string Message);
string ReadString(string Message);
void PrintCharactersCountInString(string Line);
short CountCharacter(string Line , char Character);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    PrintCharactersCountInString(Line);
}

char ReadChar(string Message)
{
    char C;
    cout<<Message<<endl;
    cin>>C;
    cout<<endl;
    return C;
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
    char Character = ReadChar("Please Enter a Character: ");

    cout<<"Letter \'"<<Character<<"\' Count = "
        << CountCharacter(Line, Character)
        <<endl;
}

short CountCharacter(string Line , char Character){
    short CharacterCount = 0;
    for (int i = 0 ; i < Line.length();i++)
        if(Line[i] == Character)
            CharacterCount++;
    return CharacterCount;
}