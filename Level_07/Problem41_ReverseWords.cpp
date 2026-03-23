#include<iostream>
#include<vector>
using namespace std;

string ReadString( string Message);
vector <string> SplitStringInVector(string Line , char Seperator);
string ReverseStringWords(string s);

int main()
{
    vector <string> vWords;
    string Line = ReadString("Please Enter Your String: ");

    cout<<"Your String In Reverse: "<<
    ReverseStringWords(Line)<<endl;
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

string ReverseStringWords(string S)
{
    vector <string> vWords = SplitStringInVector(S , ' ');
    S = "";
    for(int i = vWords.size() - 1 ; i >= 0 ; i--)
        S = S + vWords[i] + " ";
    return S.substr(0,S.length() - 1);
}