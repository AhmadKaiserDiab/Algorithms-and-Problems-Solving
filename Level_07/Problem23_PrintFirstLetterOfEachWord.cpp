#include<iostream>
#include<string>
#include<cctype>
using namespace std;

string ReadString(string Message);
void PrintFirstLetterOfEachWord(string Line);

int main()
{

    string Line = ReadString("Please Enter Your String: ");
    cout<<endl;
    PrintFirstLetterOfEachWord(Line);
}

string ReadString(string Message)
{
    string Line;
    cout<<Message<<endl;
    getline(cin,Line);
    return Line;
}

// void PrintFirstLetterOfEachWord(string  Line ) {
//     cout<<"This is The first Letters OF Each Word of The Line You Entered: \n";
//     cout<<" "<<Line[0]<< "  ";
//     for (int i = 0; i < Line.size(); i++)
//         if(Line[i] ==  ' ')
//             cout<<Line[i+1]<< "  ";
// }

void PrintFirstLetterOfEachWord(string  Line )
{
    cout<<"This is The first Letters OF Each Word of The Line You Entered: \n";
    bool isFirstLetter = true;
    for (int i = 0; i < Line.size(); i++) {
        if(Line[i] !=  ' ' && isFirstLetter)
            cout<<Line[i]<< "  ";
        isFirstLetter = Line[i] ==  ' ' ? true : false ;
    }
    cout<<endl;
}