#include <iostream>
#include <vector>
using namespace std;

string ReadString( string Message);
string LowerAllLettersInString(string line);
vector <string> SplitStringInVector(string Line , char Seperator);
string JoinString(vector <string> vWords , string Seperator);
string ReplaceWordsInString(string S , string WhereToReplace , string WhatToReplaceWith  , bool MatchCase);

int main()
{
    string Replace  , ReplaceWith , Line;
    Line = ReadString("Please Enter Your String: ");
    Replace = ReadString("Please Enter What To Replace In Your String: ");
    ReplaceWith = ReadString("Please Enter What To Replace With: ");

    cout<<"Your New String After Replacing " << Replace << " With " 
        << ReplaceWith << " With Match Case is:  "
        <<ReplaceWordsInString(Line,Replace,ReplaceWith , false)<<endl;

    cout<<endl;

    cout<<"Your New String After Replacing " << Replace << " With " 
        << ReplaceWith << " Without Match Case is:  "
        <<ReplaceWordsInString(Line,Replace,ReplaceWith)<<endl;
}

string ReadString (string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

vector <string> SplitStringInVector(string Line , char Seperator)
{
    string Word = "";
    vector <string> vWords;
    for (int i = 0; i < Line.length(); i++){
        if(Line[i] != Seperator)
            Word = Word + Line[i];
        else {
            vWords.push_back(Word);
            Word = "";
        }
    }
    if (Word != "")
        vWords.push_back(Word);
    return vWords;
}

string JoinString(vector <string> vWords , string Seperator)
{
    string S = "";
    for(string & Word : vWords )
        S = S + Word + Seperator;
    return S.substr(0,S.length() - Seperator.length());
}

string LowerAllLettersInString(string line)
{
    for (int i = 0; i < line.size(); i++)
        line[i] = tolower(line[i]);
    return line;
}

string ReplaceWordsInString(string S , string WhereToReplace , string WhatToReplaceWith  , bool MatchCase = true)
{
    vector <string> vWords = SplitStringInVector(S , ' ');

    for(string & Word : vWords)
        if(MatchCase) {
            string S1 = LowerAllLettersInString(Word);
            string S2 = LowerAllLettersInString(WhereToReplace);
            if( S1 == S2)
                Word = WhatToReplaceWith;
        }
        else
            if(Word == WhereToReplace)
                Word = WhatToReplaceWith;
    return JoinString(vWords , " ");
}