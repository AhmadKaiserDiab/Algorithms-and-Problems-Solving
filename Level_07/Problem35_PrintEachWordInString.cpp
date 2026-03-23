#include<iostream>
using namespace std;

string ReadString(string Message);
void PrintEachWordInString(string Line);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    PrintEachWordInString(Line);
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

void PrintEachWordInString(string S1)
{
    cout << "\nYour string wrords are: \n\n";

    string delim = " "; // delimiter
    string sWord; // define a string variable

    short pos = 0;

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "") 
            cout << sWord << endl;
        S1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
    }
    if (S1 != "") 
        cout << S1 << endl; // it print The last word of the string.
}