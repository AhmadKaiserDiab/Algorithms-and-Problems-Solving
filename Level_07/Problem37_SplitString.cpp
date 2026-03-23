#include<iostream>
#include<vector>
using namespace std;

string ReadString(string Message);
void SplitStringInVector(string Line , vector <string> & Words);
void PrintStringWords(string Line);

int main()
{
    string Line = ReadString("Please Enter Your String: ");
    PrintStringWords(Line);
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    cout<<endl;
    return Line;
}

//* This Works Only With one Character
void SplitStringInVector(string Line , char seperator, vector <string> & vWords)
{
    string Word = "";
    for (int i = 0; i < Line.length(); i++){
        if(Line[i] != seperator)
            Word = Word + Line[i];
        else {
            vWords.push_back(Word);
            Word = "";
        }
    }
    if (Word != "")
    vWords.push_back(Word);
}

void PrintStringWords(string Line)
{
    vector <string> vWords;
    SplitStringInVector(Line , 'a' ,vWords);
    cout<<"Tokens = "<<vWords.size()<<endl;
    for(string & word : vWords)
        cout<<word<<endl;
}

/*
vector<string> SplitString(string S1, string Delim) 
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word

        if (sWord != "")
            vString.push_back(sWord);

        // erase() until positon and move to next word.
        S1.erase(0, pos + Delim.length()); 
        }
        if (S1 != "")
            vString.push_back(S1); // it adds last word of the string.
    return vString;
}
*/