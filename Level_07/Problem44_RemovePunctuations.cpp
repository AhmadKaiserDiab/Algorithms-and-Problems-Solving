#include <iostream>
using namespace std;

string ReadString(string Message);
string RemovePunctuations(string s);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    cout<<"Your Original string: "<<Line<<endl;
    cout<<"You String After ReRemoving Punctuations: "<<RemovePunctuations(Line)<<endl;
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

string RemovePunctuations(string S)
{
    for(int i = 0 ; i < S.length(); i++)
        if(ispunct(S[i]))
            S.erase(i--,1);
    return S;
}