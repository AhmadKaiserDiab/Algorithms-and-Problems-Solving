#include<iostream>
#include<vector>
using namespace std;

string ReadString( string Message);
vector <string> SplitStringInVector(string Line , char Seperator);
string JoinString(vector <string> vWords , string Seperator);

int main()
{
    vector <string> vWords;
    string Line = ReadString("Please Enter Your String: ");

    vWords = SplitStringInVector(Line , ' ');

    cout<<"Your string After Seperated Into Words: "<<endl;
        for(string & word : vWords)
            cout<<word<<endl;
        cout<<endl;

    cout<<"\nYour Words After Joined Into String: "
    <<JoinString(vWords , "  XXX  ")<<endl;
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