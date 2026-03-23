#include<iostream>
#include<vector>
using namespace std;

string ReadString(string Message);
string JoinString(vector<string> vWords , string Seperator);
string JoinString(string arrWords[], short length , string Seperator);

int main()
{
    vector <string> vWords = { "Ahmad" , "Kaiser" , "Diab" } ;
    string arrWords[3] =     { "Ahmad" , "Kaiser" , "Diab" } ;

    cout<<"\n Vector Words After Join: "<<JoinString(vWords , " ")<<endl;
    cout<<"\n Array Words After Join:  "<<JoinString(arrWords , 3 , " ")<<endl;
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

string JoinString( vector <string> vWords , string Seperator )
{
    string S = "";
    for( string & Word : vWords )
        S = S + Word + Seperator;
    return S.substr(0,S.length() - Seperator.length());
}

string JoinString( string arrWords[], short length , string Seperator )
{
    string S = "";
    for(int i = 0 ; i < length ; i++ )
        S = S + arrWords[i] + Seperator;
    return S.substr(0,S.length() - Seperator.length());
}