#include<iostream>
using namespace std;

string ReadString(string Message);
string TrimLeft(string s);
string TrimRight(string s);
string TrimAll(string s);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    cout<<"Your Original string: "<<Line<<endl;
    cout<<"You String After Left Trim: "<<TrimLeft(Line)<<endl;
    cout<<"You String After Right Trim: "<<TrimRight(Line)<<endl;
    cout<<"You String After Both Sides Trim: "<<TrimAll(Line)<<endl;
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

string TrimLeft(string S)
{
    for (short i = 0; i < S.length(); i++)
    {
        if (S[i] != ' ')
        {
        return S.substr(i, S.length() - i);
        }
    }
    return "";
}

string TrimRight(string S)
{
    for (short i = S.length() - 1; i >= 0; i--)
    {
        if (S[i] != ' ')
        {
            return S.substr(0, i + 1);
        }
    }
    return "";
}

string TrimAll(string S)
{
    return TrimLeft(TrimRight(S));
}
