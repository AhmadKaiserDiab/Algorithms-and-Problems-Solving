#include<iostream>
using namespace std;

string ReadString(string Message);
short CountEachWordInString(string Line);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    cout<<"The Number Of Words In Your String Is: "
        <<CountEachWordInString(Line)
        <<endl;
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

short CountEachWordInString(string S1)
{
    short WordsCount = 0;

    string delim = " "; // delimiter
    string sWord; // define a string variable

    short pos = 0;

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "") 
            WordsCount++;
        S1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
    }
    if (S1 != "") 
        WordsCount++; // it Counts The last word of the string.

    return WordsCount;
}